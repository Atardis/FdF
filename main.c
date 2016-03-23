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

int		my_fonct_key(int keycode, t_a *a)
{
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend");
	if (keycode == UP)
		fdf_modif_up(a);
	if (keycode == DOWN)
		fdf_modif_down(a);
	if (keycode == LEFT)
		fdf_modif_left(a);
	if (keycode == RIGHT)
		fdf_modif_right(a);
	if (keycode == PLUS)
		ft_modif_plus(a);
	if (keycode == MINUS)
		ft_modif_minus(a);
	return (0);
}

void ft_put_pixel_to_image(t_a *a, int y, int x, int color)
{
	if (x >= 0 && x <= a->e.size && y >= 0 && y <= a->e.size)
		*(unsigned int*)(a->e.data + (x * a->e.bpp) + (y * a->e.sl)) = color;
}


void init(t_a *a)
{
	if (!(a->e.mlx = mlx_init()))
	  ft_error("initialisation mlx_init error");
	if (!(a->e.win = mlx_new_window(a->e.mlx, a->e.size, a->e.size, "Yolo")))
		ft_error("initialisation mlx_new_windows error");
	a->e.img = mlx_new_image(a->e.mlx, a->e.size + 1 , a->e.size + 1);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	a->e.bpp /= 8;
}

int main(int argc, char **argv)
{
	t_a a;
	char 	*line;
	int		y;
	int 	i;

	define_struct(&a);
	if (argc < 2)
		ft_error("Pas le bon nombre d'argument");
	if ((a.e.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	a.e.max_line = 0;
	a.e.nb_caract = 0;
	while (get_next_line(a.e.fd, &line) > 0)
	{
		if (a.e.max_line == 0)
			a.e.nb_caract = count_carac(line);
		if (a.e.max_line != 0)
			if (a.e.nb_caract != count_carac(line))
				ft_error("Fichier Invalide");
		a.e.max_line++;
	}
	close(a.e.fd);
	a.map = fonction_creat_struct(&a);
	if ((a.e.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = -1;
	i = 0;
	while ((i = get_next_line(a.e.fd, &line)) > 0 && ++y < a.e.max_line)
		send_map_to_struct(a, line, y);
	init(&a);
	ft_print_to_image_bresenham(&a);
//	ft_print_map_to_image(&a);
	mlx_hook(a.e.win, 2, (1L<<01), my_fonct_key, &a);
	mlx_loop(a.e.mlx);
	return (0);
}
