/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 07:29:15 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 07:29:17 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_space(char *line)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if ((line[index] >= '0' && line[index] <= '9') || line[index] == '-')
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

t_fdfpoint	**fonction_creat_struct(t_fdfpoint **mlxmap, int max_line, int nb_caract)
{
	unsigned int y;
	int x;

	if (!(mlxmap = (t_fdfpoint **)malloc(sizeof(t_fdfpoint *) * max_line)))
		ft_error("Malloc has Failed for the struct Y");
	y = -1;
	while (++y < max_line)
	{
		if (!(mlxmap[y] = (t_fdfpoint *)malloc(sizeof(t_fdfpoint) * nb_caract)))
			ft_error("Malloc has Failed for the struct X");
			x = -1;
		while (++x < nb_caract)
		{
			mlxmap[y][x].z = 0;
			mlxmap[y][x].y = y;
			mlxmap[y][x].x = x;
			mlxmap[y][x].color = 0;
		}
	}
	return(mlxmap);
}

void		send_map_to_struct(t_fdfpoint **mlxmap, char *str, int y, int nb_caract)
{
	int i;
	int x;
	int point;

	i = 0;
	point = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while ((str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) && point == 0 && x < nb_caract)
		{
			point = 1;
			mlxmap[y][x].z = ft_atoi_re(str, i);
			x++;
		}
		while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		point = 0;
	}
}

void		ft_print_struct(t_fdfpoint **mlxmap, int max_line, int nb_caract)
{
	int y;
	int x;

	y = -1;
	while (++y < max_line)
	{
		x = -1;
		while (++x < nb_caract)
		{
			ft_putnbr(mlxmap[y][x].z);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}