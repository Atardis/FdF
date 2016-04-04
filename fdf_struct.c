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

t_map						**fonction_creat_struct(t_a *a)
{
	unsigned int	y;
	unsigned int	x;

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

void						send_map_to_struct(t_a *a, char *str, int y)
{
	int						i;
	int						x;
	int						find;

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
