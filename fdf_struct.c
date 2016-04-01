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

void	define_struct(t_a *a)
{
	a->e.size = 1300;
	a->e.origin_y = 300;
	a->e.origin_x = 300;
	a->e.space = 10;
	a->e.zoom_in = 1;
	a->e.zoom_out = 1;
}

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
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (a->map[y][x].z > a->e.z_max)
				a->e.z_max = a->map[y][x].z;
			else if (a->map[y][x].z < a->e.z_min)
				a->e.z_min = a->map[y][x].z;
		}
	}
	size_max_z_to_min_z(a);
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
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
			a->map[y][x].color = (localisation_color(a, a->map[y][x].z));
	}
}

int	localisation_color(t_a *a, int z)
{
	double r;

	r = a->e.distance_z / 10;
	if (z >= a->e.z_min && z < (a->e.z_min + (r * 1)))
		return (RED);
	else if (z >= (a->e.z_min + (r)) && z < (a->e.z_min + (r * 2)))
		return (ORANGE);
	else if  (z >= (a->e.z_min + (r * 2)) && z < (a->e.z_min + (r * 3)))
		return (YELLOW);
	else if (z >= (a->e.z_min + (r * 3)) && z < (a->e.z_min + (r * 4)))
		return (LIMON);
	else if (z >= (a->e.z_min + (r * 4)) && z < (a->e.z_min + (r* 5)))
		return (RAZER);
	else if (z >= (a->e.z_min + (r * 5)) && z < (a->e.z_min + (r * 6)))
		return (WGREEN);
	else if (z >= (a->e.z_min + (r * 6)) && z < (a->e.z_min + (r * 7)))
		return (LAGON);
	else if (z >= (a->e.z_min + (r * 7)) && z < (a->e.z_min + (r * 8)))
		return (SKY);
	else if (z >= (a->e.z_min + (r * 8)) && z < (a->e.z_min + (r  * 9)))
		return (BLUE_C);
	else if (z >= (a->e.z_min + (r * 9)) && z <= a->e.distance_z)
		return (BLUE);
	return (0xFFFFFF);
}


t_map					**fonction_creat_struct(t_a *a)
{
	unsigned int	y;
	int						x;

	if (!(a->map = (t_map **)malloc(sizeof(t_map *) * a->e.max_line)))
		ft_error("Malloc has Failed for the struct Y");
	y = -1;
	while (++y < a->e.max_line)
	{
		if (!(a->map[y] = (t_map *)malloc(sizeof(t_map) * a->e.nb_caract)))
			ft_error("Malloc has Failed for the struct X");
		x = -1;
		while (++x < a->e.nb_caract)
		{
			a->map[y][x].z = 0;
			a->map[y][x].y = y;
			a->map[y][x].x = x;
			a->map[y][x].color = 0;
		}
	}
	return (a->map);
}

void		send_map_to_struct(t_a *a, char *str, int y)
{
	int i;
	int x;
	int find;

	i = 0;
	find = 0;
	x = 0;
	while (str[i] && y < a->e.max_line)
	{
		while (str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) &&
				find == 0 && x < a->e.nb_caract)
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
