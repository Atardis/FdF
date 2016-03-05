/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 00:27:13 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 00:27:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft/includes/libft.h"

int		my_fonct_key(int keycode, t_mlxstore *MLX)
{
	ft_putstr("key event ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	mlx_pixel_put(MLX->mlx, MLX->win, 300, 300, 0x33CC00);
	if (keycode == 53)
		exit(0);
	return (0);
}

int main()
{
	static t_mlxstore	MLX;
	int x;
	int y;

	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, 1000, 1000, "Ma Bite");
	y = 49;
	while (++y < 150)
	{
		x = 49;
		while (++x < 150)
			mlx_pixel_put(MLX.mlx, MLX.win, x, y, 0x00FF00CC);
	}
	mlx_key_hook(MLX.win, my_fonct_key, &MLX);
	mlx_loop(MLX.mlx);
	return (0);
}