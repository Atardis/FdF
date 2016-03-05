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

#include "fdf.h"

void	ft_put_key_nb(int keycode)
{
	ft_putstr("key event ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	ft_putendl("--------------");
}

int		my_fonct_key(int keycode, t_mlxstore *MLX)
{
	ft_put_key_nb(keycode);
	if (keycode == 53)
	{
		ft_putchar('\n');
		ft_putendl("ESC : Good Bye My Friend");
		exit(0);
	}
	if (keycode == 126)
		ft_up(keycode, MLX);
	if (keycode == 125)
		ft_down(keycode, MLX);
	if (keycode == 123)
		ft_left(keycode, MLX);
	if (keycode == 124)
		ft_right(keycode, MLX);
	return (0);
}

void	ft_test(int i)
{
	static 	t_mlxstore	MLX;
	int 	x;
	int 	y;

	(void)i;
	MLX.x = 449;
	MLX.y = 449;
	MLX.move = 100;
	y = MLX.y;
	x = MLX.x;
	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, 1000, 1000, "Ma Bite");
	y = 449;
	while (++y < 550)
	{
		x = 449;
		while (++x < 550)
			mlx_pixel_put(MLX.mlx, MLX.win, x, y, 0x00FF6600);
	}
	mlx_key_hook(MLX.win, my_fonct_key, &MLX);
	mlx_loop(MLX.mlx);
}



int main()
{
	
	ft_test(1);
	return (0);
}