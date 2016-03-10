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

void	color(int keycode, t_mlxstore *MLX)
{
	if (keycode == 11)
		MLX->color = 0x004189DD;
	if (keycode == 9)
		MLX->color = 0x0055BE47;
	if (keycode == 15)
		MLX->color = 0x00C10435;
}

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
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, MLX->color);
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
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, MLX->color);
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
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, MLX->color);
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
			mlx_pixel_put(MLX->mlx, MLX->win, x, y, MLX->color);
	}
}

char *fonct_line(char *str)
{
	int i;
	int **tab;
	int x;
	int y;

	count_space(line);
	tab = (int **)malloc(count_space(line) * sizeof(int *))
	y = -1
	while (++y < count_space(line))
	{
		tab[y] = (int *)malloc(count_space(line) * sizeof(int))
		x = -1;
		while ()
	}
}

void	print_map_to_win(t_mlxstore *MLX, char *line, int y)
{
	int i;
	int j;

	i = -1;
	j = 5;
	fonct_line(line);
	while (line[++i])
	{
		if (line[i] == '0')
			mlx_pixel_put(MLX->mlx, MLX->win, j, y, 0x00E55300);
		else if (line[i] == '1')
		{
			mlx_pixel_put(MLX->mlx, MLX->win, j, y, 0x0055BE47);
			i++;
		}
		j = j + 5;
	}
}
