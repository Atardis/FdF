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

void	ft_up(int keycode, t_mlxstore *MLX)
{
	int y;
	int x;

	MLX->y = MLX->y - 120;
	y = MLX->y - 1;
	while (++y < MLX->y + MLX->move)
	{
		x = MLX->x - 1;
		while (++x < MLX->x + MLX->move)
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, 0x00FF6600);
	}
}

void	ft_down(int keycode, t_mlxstore *MLX)
{
	int y;
	int x;

	MLX->y = MLX->y + 120;
	y = MLX->y - 1;
	while (++y < MLX->y + MLX->move)
	{
		x = MLX->x - 1;
		while (++x < MLX->x + MLX->move)
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, 0x00FF6600);
	}
}

void	ft_left(int keycode, t_mlxstore *MLX)
{
	int y;
	int x;

	MLX->x = MLX->x - 120;
	y = MLX->y - 1;
	while (++y < MLX->y + MLX->move)
	{
		x = MLX->x - 1;
		while (++x < MLX->x + MLX->move)
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, 0x00FF6600);
	}
}

void	ft_right(int keycode, t_mlxstore *MLX)
{
	int y;
	int x;

	MLX->x = MLX->x + 120;
	y = MLX->y - 1;
	while (++y < MLX->y + MLX->move)
	{
		x = MLX->x - 1;
		while (++x < MLX->x + MLX->move)
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, 0x00FF6600);
	}
}