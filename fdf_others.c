/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:41:34 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/04 13:41:37 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void						size_z_max_min(t_a *a)
{
	int						y;
	int						x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			if (a->map[y][x].z > a->e.z_max)
				a->e.z_max = a->map[y][x].z;
			else if (a->map[y][x].z < a->e.z_min)
				a->e.z_min = a->map[y][x].z;
		}
	}
	size_max_z_to_min_z(a);
}

void						ft_modif_z(t_a *a, int keycode)
{
	int						y;
	int						x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			if (keycode == EGAL)
				a->map[y][x].z *= 1.1;
			else if (keycode == UNDER)
				a->map[y][x].z /= 1.1;
		}
	}
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

void						size_max_z_to_min_z(t_a *a)
{
	if (a->e.z_min < 0)
		a->e.distance_z = a->e.z_max - a->e.z_min;
	else if (a->e.z_min >= 0)
		a->e.distance_z = a->e.z_max + a->e.z_min;
	put_color(a);
}

int							recover_point(t_a *a, int x, int y, char c)
{
	int						xx;
	int						yy;

	xx = 1 + x;
	yy = 1 + y;
	if (x < a->e.max_x && xx < a->e.max_x && c == 'x' && x >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 1.5) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[y][xx].x - ((a->map[y][xx].y / 1.5) * a->e.iso);
		a->p2.y = a->map[y][xx].y - a->map[y][xx].z;
		return (1);
	}
	if (y < a->e.max_y && yy < a->e.max_y && c == 'y' && y >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 1.5) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[yy][x].x - ((a->map[yy][x].y / 1.5) * a->e.iso);
		a->p2.y = a->map[yy][x].y - a->map[yy][x].z;
		return (1);
	}
	return (0);
}
