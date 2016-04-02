/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:17:26 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/21 13:17:28 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_carac(char *line)
{
	int index;
	int count;

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

void size_z_max_min(t_a *a)
{
	int y;
	int x;

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

void ft_modif_z(t_a *a, int keycode)
{
	int y;
	int x;

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

void size_max_z_to_min_z(t_a *a)
{
	int i;

	if (a->e.z_min < 0)
		a->e.distance_z = a->e.z_max - a->e.z_min;
	else if (a->e.z_min >= 0)
		a->e.distance_z = a->e.z_max + a->e.z_min;
	put_color(a);
}

void put_color(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
			a->map[y][x].color = (localisation_color(a, a->map[y][x].z));
	}
}

t_map					**fonction_creat_struct(t_a *a)
{
	unsigned int	y;
	int						x;

	if (!(a->map = (t_map **)malloc(sizeof(t_map *) * a->e.max_y)))
		ft_error("Malloc has Failed for the struct Y", a);
	y = -1;
	while (++y < a->e.max_y)
	{
		if (!(a->map[y] = (t_map *)malloc(sizeof(t_map) * a->e.max_x)))
			ft_error("Malloc has Failed for the struct X", a);
		x = -1;
		while (++x < a->e.max_x)
		{
			a->map[y][x].z = 0;
			a->map[y][x].y = y;
			a->map[y][x].x = x;
			a->map[y][x].color = 0;
		}
	}
	return (a->map);
}

void iso_modif(t_a *a)
{
	int x;
	int y;
	double re;

	a->e.iso *= -1;
	y = -1;
	re = distance(a);
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			if (a->e.iso < 0)
				a->map[y][x].x -= re;
			else
				a->map[y][x].x += re;
		}
	}
	print(a);
}

double			distance(t_a *a)
{
	int x;
	double min_x;
	double max_x;
	double distance;

	x = -1;
	while (++x < a->e.max_x)
	{
			if (a->map[0][x].x > max_x)
				max_x = a->map[0][x].x;
			else if (a->map[0][x].x < min_x)
				min_x = a->map[0][x].x;
	}
	distance = max_x - min_x;
	return (distance / 2);
}

void		send_map_to_struct(t_a *a, char *str, int y)
{
	int i;
	int x;
	int find;

	i = 0;
	find = 0;
	x = 0;
	while (str[i] && y < a->e.max_y)
	{
		while (str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) &&
				find == 0 && x < a->e.max_x)
		{
			find = 1;
			a->map[y][x].z = ft_atoi_re(str, i);
			x++;
		}
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'A' && str[i] <= 'F') || str[i] == ',' || str[i] == 'x'))
			i++;
		find = 0;
	}
}
