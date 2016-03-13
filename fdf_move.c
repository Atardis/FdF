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
	int y;
	int x;

	if (!(mlxmap = (t_fdfpoint **)malloc(sizeof(t_fdfpoint *) * max_line)))
		ft_error("Malloc has Failed for the struct");
	y = -1;
	while (++y < max_line)
		if (!(mlxmap[y] = (t_fdfpoint *)malloc(sizeof(t_fdfpoint) * nb_caract)))
			ft_error("Malloc has Failed for the struct");
	return(mlxmap);
}

void		ft_map_in_struct(t_fdfpoint mlxmap, int i)
{
	int index;

	index = -1;
	while ()
}

//0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0