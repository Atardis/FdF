/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fucking_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:02:29 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/12 16:02:33 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_key_nb(int keycode)
{
	ft_putendl("--------------");
	ft_putstr("touche: ");
	if (keycode == UP)
		ft_putchar(94);
	else if (keycode == DOWN)
		ft_putchar(118);
	else if (keycode == LEFT)
		ft_putchar(60);
	else if (keycode == RIGHT)
		ft_putchar(62);
	else if (keycode == EXIT)
		ft_putstr("EXIT");
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
}

int		my_fonct_key(int keycode, t_mlxstore *mlx)
{
	ft_put_key_nb(keycode);
	if (keycode == EXIT)
		ft_exit();
	if (keycode == UP)
		ft_up(keycode, mlx);
	if (keycode == DOWN)
		ft_down(keycode, mlx);
	if (keycode == LEFT)
		ft_left(keycode, mlx);
	if (keycode == RIGHT)
		ft_right(keycode, mlx);
	else
		color(keycode, mlx);
	return (0);
}

void	color(int keycode, t_mlxstore *mlx)
{
	if (keycode == 11)
		mlx->color = 0x004189DD;
	if (keycode == 9)
		mlx->color = 0x0055BE47;
	if (keycode == 15)
		mlx->color = 0x00C10435;
}

void	ft_up(int keycode, t_mlxstore *mlx)
{
	int y;
	int x;

	mlx->y = mlx->y - 120;
	y = mlx->y - 1;
	while (++y < mlx->y + mlx->move)
	{
		x = mlx->x - 1;
		while (++x < mlx->x + mlx->move)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, mlx->color);
	}
}

void	ft_down(int keycode, t_mlxstore *mlx)
{
	int y;
	int x;

	mlx->y = mlx->y + 120;
	y = mlx->y - 1;
	while (++y < mlx->y + mlx->move)
	{
		x = mlx->x - 1;
		while (++x < mlx->x + mlx->move)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, mlx->color);
	}
}

void	ft_left(int keycode, t_mlxstore *mlx)
{
	int y;
	int x;

	mlx->x = mlx->x - 120;
	y = mlx->y - 1;
	while (++y < mlx->y + mlx->move)
	{
		x = mlx->x - 1;
		while (++x < mlx->x + mlx->move)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, mlx->color);
	}
}

void	ft_right(int keycode, t_mlxstore *mlx)
{
	int y;
	int x;

	mlx->x = mlx->x + 120;
	y = mlx->y - 1;
	while (++y < mlx->y + mlx->move)
	{
		x = mlx->x - 1;
		while (++x < mlx->x + mlx->move)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, mlx->color);
	}
}
