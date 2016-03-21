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

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void ft_print_map_to_image(t_a *a)
{
	int y;
	int x;
	int color;
	int color2;
	int i;

	color = 0xFFFFFF;
	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (a->map[y][x].z == 0)
				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, color);
			else
				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFF0000);
		}
	}
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	i = mlx_destroy_image(a->e.mlx, a->e.img);
}
