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

int		count_carac(char *line)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (line[index] == '-' || (line[index] >= '0' && line[index] <= '9'))
		{
			count++;
			while (line[index] && line[index] != ' ')
				index++;
		}
		else
			index++;
	}
	return (count);
}

void	size_z_max_min(t_a *a)
{
	int	y;
	int	x;

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

void	ft_modif_z(t_a *a, int keycode)
{
	int	y;
	int	x;

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

void	size_max_z_to_min_z(t_a *a)
{
	int	i;

	if (a->e.z_min < 0)
		a->e.distance_z = a->e.z_max - a->e.z_min;
	else if (a->e.z_min >= 0)
		a->e.distance_z = a->e.z_max + a->e.z_min;
	put_color(a);
}

int			recover_point(t_a *a, int x, int y, char c)
{
	int		X;
	int		Y;

	X = 1 + x;
	Y = 1 + y;
	if (x < a->e.max_x && X < a->e.max_x && c == 'x' && x >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 1.5) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[y][X].x - ((a->map[y][X].y / 1.5) * a->e.iso);
		a->p2.y = a->map[y][X].y - a->map[y][X].z;
		return (1);
	}
	if (y < a->e.max_y && Y < a->e.max_y && c == 'y' && y >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 1.5) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[Y][x].x - ((a->map[Y][x].y / 1.5) * a->e.iso);
		a->p2.y = a->map[Y][x].y - a->map[Y][x].z;
		return (1);
	}
	return (0);
}
