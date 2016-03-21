/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:52:56 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/19 13:53:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_modif_plus(t_a *a)
{
	int x;
	int y;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = 0;
		a->map[y][0].y *= 2;
		while (++x < a->e.nb_caract)
		{
			a->map[y][x].x *= 2;
			a->map[y][x].y *= 2;
		}
	}
	mlx_clear_window(a->e.mlx, a->e.win);
	fdf_new_image(a);
	ft_print_map_to_image(a);
}

void	ft_modif_minus(t_a *a)
{
	int x;
	int y;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = 0;
		a->map[y][0].y /= 2;
		while (++x < a->e.nb_caract)
		{
			a->map[y][x].x /= 2;
			a->map[y][x].y /= 2;
		}
	}
	mlx_clear_window(a->e.mlx, a->e.win);
	fdf_new_image(a);
	ft_print_map_to_image(a);
}
