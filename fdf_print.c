/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:17:18 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/21 13:17:20 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_print_to_image_bresenham(t_a *a)
{
	int		y;
	int		x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
			ft_print_to_image_b_while(a, x, y);
	}
	fdf_recover_size(a);
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	ft_put_info(a);
	mlx_destroy_image(a->e.mlx, a->e.img);
}

void		ft_print_to_image_b_while(t_a *a, int x, int y)
{
	if ((recover_point(a, x, y, 'x')) > 0)
	{
		if (a->map[y][x].z < a->map[y][x + 1].z)
			ligne(a, a->map[y][x + 1].color);
		else if (a->map[y][x].z > a->map[y][x + 1].z ||
			a->map[y][x].z == a->map[y][x + 1].z)
			ligne(a, a->map[y][x].color);
	}
	if ((recover_point(a, x, y, 'y')) > 0)
	{
		if (a->map[y][x].z < a->map[y + 1][x].z)
			ligne(a, a->map[y + 1][x].color);
		else if (a->map[y][x].z > a->map[y + 1][x].z ||
			a->map[y][x].z == a->map[y + 1][x].z)
			ligne(a, a->map[y][x].color);
	}
}

void		ligne(t_a *a, int color)
{
	a->b.x = a->p1.x;
	a->b.y = a->p1.y;
	a->b.dx = a->p2.x - a->p1.x;
	a->b.dy = a->p2.y - a->p1.y;
	a->b.xinc = (a->b.dx > 0) ? 1 : -1;
	a->b.yinc = (a->b.dy > 0) ? 1 : -1;
	a->b.dx = abs(a->b.dx);
	a->b.dy = abs(a->b.dy);
	ft_p_pixel_image(a, a->b.y, a->b.x, color);
	if (a->b.dx > a->b.dy)
		ligne_if(a, color);
	else
		ligne_else(a, color);
}

void		ligne_if(t_a *a, int color)
{
	a->b.cumul = a->b.dx / 2;
	a->b.i = 0;
	while (++a->b.i <= a->b.dx)
	{
		a->b.x += a->b.xinc;
		a->b.cumul += a->b.dy;
		if (a->b.cumul >= a->b.dx)
		{
			a->b.cumul -= a->b.dx;
			a->b.y += a->b.yinc;
		}
		ft_p_pixel_image(a, a->b.y, a->b.x, color);
	}
}

void		ligne_else(t_a *a, int color)
{
	a->b.cumul = a->b.dy / 2;
	a->b.i = 0;
	while (++a->b.i <= a->b.dy)
	{
		a->b.y += a->b.yinc;
		a->b.cumul += a->b.dx;
		if (a->b.cumul >= a->b.dy)
		{
			a->b.cumul -= a->b.dy;
			a->b.x += a->b.xinc;
		}
		ft_p_pixel_image(a, a->b.y, a->b.x, color);
	}
}
