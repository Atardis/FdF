/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 00:27:13 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 00:27:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_struct(t_all *all)
{
	all->env.size_x = 1000;
	all->env.size_y = 1000;
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		my_fonct_key(int keycode, t_all *all)
{
	ft_putnbr_end(keycode);
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend");
	return (0);
}

void ft_put_pixel_to_image(t_all *all, int y, int x, int color)
{
	int i;
	int j;

	j = 10;
	i = 10;
	if (x < 0 || x > all->env.width || y < 0 || y > all->env.height)
		ft_error("probleme de put_pixel");
	*(unsigned int*)(all->env.data + ((i + x) * 15) * all->env.bpp + ((j + y) * 15) * all->env.sl) = mlx_get_color_value(all->env.mlx, color);
}


void init(t_all *all)
{
	if (!(all->env.mlx = mlx_init()))
	  ft_error("initialisation mlx_init error");
	if (!(all->env.win = mlx_new_window(all->env.mlx, all->env.width, all->env.height, "Yolo")))
		ft_error("initialisation mlx_new_windows error");
	all->env.img = mlx_new_image(all->env.mlx, all->env.width, all->env.height);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl, &all->env.ed);
	all->env.bpp /= 8;
}

int main(int argc, char **argv)
{
	t_all all;
	char 	*line;
	int		y;
	int 	i;


	all.env.width = 1000;
	all.env.height = 1000;
	define_struct(&all);
	if (argc < 2)
		ft_error("Pas le bon nombre d'argument");
	if ((all.env.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	all.env.max_line = 0;
	all.env.nb_caract = 0;
	while (get_next_line(all.env.fd, &line) > 0)
	{
		if (all.env.max_line == 0)
			all.env.nb_caract = count_carac(line);
		if (all.env.max_line != 0)
			if (all.env.nb_caract != count_carac(line))
				ft_error("Fichier Invalide");
		all.env.max_line++;
	}
	close(all.env.fd);
	all.map = fonction_creat_struct(&all);
	if ((all.env.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = -1;
	i = 0;
	while ((i = get_next_line(all.env.fd, &line)) > 0 && ++y < all.env.max_line)
		send_map_to_struct(all, line, y);
	ft_print_struct(all.map, all.env.max_line, all.env.nb_caract);
	init(&all);
	ft_print_map_to_image(&all);
	mlx_key_hook(all.env.win, my_fonct_key, &all);
	mlx_loop(all.env.mlx);
	return (0);
}
