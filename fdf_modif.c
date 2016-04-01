/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:11:21 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/21 21:11:24 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fdf_recover_size_o(t_a *a)
{
	a->e.size_x = (a->map[0][a->e.nb_caract - 1].x - a->map[0][0].x);
	a->e.size_y = (a->map[a->e.max_line - 1][0].y - a->map[0][0].y);
}

void fdf_recover_size(t_a *a)
{
	a->e.size_X = (a->map[0][a->e.nb_caract - 1].x - a->map[0][0].x);
	a->e.size_Y = (a->map[a->e.max_line - 1][0].y - a->map[0][0].y);
}

void fdf_move(t_a *a)
{
	a->e.move_x = ((a->e.size_X - a->e.size_x) / 2);
	a->e.move_y = ((a->e.size_Y - a->e.size_y) / 2);
}

void	fdf_modif_pos(t_a *a, int keycode)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (keycode == LEFT)
				a->map[y][x].x -= 10;
			else if (keycode == RIGHT)
				a->map[y][x].x += 10;
			else if (keycode == UP)
				a->map[y][x].y -= 10;
			else if (keycode == DOWN)
				a->map[y][x].y += 10;
		}
	}
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

void	ft_modif_size(t_a *a, int keycode)
{
	int x;
	int y;

	y = -1;
	fdf_recover_size_o(a);
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (keycode == PLUS)
			{
				a->map[y][x].x *= 1.1;
				a->map[y][x].y *= 1.1;
			}
			else
			{
				a->map[y][x].x /= 1.1;
				a->map[y][x].y /= 1.1;
			}
		}
	}
	fdf_recover_size(a);
	fdf_move(a);
	move_map(a);
	mlx_clear_window(a->e.mlx, a->e.win);
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

void ft_background(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.size)
	{
		x = -1;
		while (++x < a->e.size)
			ft_put_pixel_to_image(a, y, x, BACKGROUND);
	}
}

void	fdf_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, a->e.size, a->e.size);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_error("probleme get_data");
	a->e.bpp /= 8;
	if (a->e.background < 0)
		ft_background(a);
}
