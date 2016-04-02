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

int				my_fonct_key(int keycode, t_a *a)
{
	ft_putnbr_end(keycode);
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend");
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		fdf_modif_pos(a, keycode);
	if (keycode == PLUS || keycode == MINUS)
		ft_modif_size(a, keycode);
	if (keycode == B)
	{
		a->e.background *= -1;
		print(a);
	}
	if (keycode == UNDER || keycode == EGAL)
	{
		if (keycode == EGAL)
			ft_modif_z(a, '+');
		else
			ft_modif_z(a, '-');
	}
	if (keycode == I)
	{
		a->e.info *= -1;
		print(a);
	}
	if (keycode == T)
	{
		a->e.iso *= -1;
		print(a);
	}
	return (0);
}

void				print(t_a *a)
{
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

void			ft_put_pixel_to_image(t_a *a, int y, int x, int color)
{
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
		*(unsigned int*)(a->e.data + (x * (a->e.bpp)) + (y * a->e.sl)) = color;
}

void				init(t_a *a)
{
	if (!(a->e.mlx = mlx_init()))
		ft_error("initialisation mlx_init error");
	if (!(a->e.win = mlx_new_window(a->e.mlx, 1920, 1080, "FDF")))
		ft_error("initialisation mlx_new_windows error");
	a->e.background = 1;
	a->e.info = -1;
	a->e.iso = -1;
	fdf_new_image(a);
}

static void	read_file(t_a *a, char *str, int y, int i)
{
	char			*line;

	while ((a->e.tmp = get_next_line(a->e.fd, &line)) > 0)
	{
		if (a->e.max_y == 0)
			a->e.max_x = count_carac(line);
		if (a->e.max_y != 0)
			if (a->e.max_x != count_carac(line))
				ft_error("Fichier Invalide");
		a->e.max_y++;
		free(line);
	}
	if (a->e.tmp == -1)
		ft_error("Probleme de Lecture / Pas bon fichier donné");
	close(a->e.fd);
	a->map = fonction_creat_struct(a);
	if ((a->e.fd = open(str, O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = -1;
	i = 0;
	while ((i = get_next_line(a->e.fd, &line)) > 0 && ++y < a->e.max_y)
	{
		send_map_to_struct(a, line, y);
		free(line);
	}
}

int					main(int argc, char **argv)
{
	t_a				a;
	int				y;
	int				i;

	if (argc < 2)
		ft_error("Pas le bon nombre d'argument");
	if ((a.e.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	a.e.max_x = 0;
	a.e.max_y = 0;
	read_file(&a, argv[1], y, i);
	size_z_max_min(&a);
	init(&a);
	ft_print_to_image_bresenham(&a);
	mlx_hook(a.e.win, 2, (1L << 01), my_fonct_key, &a);
	mlx_loop(a.e.mlx);
	return (0);
}
