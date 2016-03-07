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
	ft_putstr("touche: ");
	if (keycode == UP)
		ft_putchar(94);
	if (keycode == DOWN)
		ft_putchar(118);
	if (keycode == LEFT)
		ft_putchar(60);
	if (keycode == RIGHT)
		ft_putchar(62);
	if (keycode == EXIT)
		ft_putstr("EXIT");
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
	ft_putendl("--------------");
}

void	ft_exit(void)
{
	ft_putchar('\n');
	ft_putendl("ESC : Good Bye My Friend");
	exit(3);
}

int		my_fonct_key(int keycode, t_mlxstore *MLX)
{
	ft_put_key_nb(keycode);
	if (keycode == EXIT)
		ft_exit();
	if (keycode == UP)
		ft_up(keycode, MLX);
	if (keycode == DOWN)
		ft_down(keycode, MLX);
	if (keycode == LEFT)
		ft_left(keycode, MLX);
	if (keycode == RIGHT)
		ft_right(keycode, MLX);
	else
		color(keycode, MLX);
	return (0);
}

// int		my_fonct_mouse(int keycode, t_mlxstore *MLX)
// {
// 	ft_put_key_nb(keycode);
// 	if (keycode == 4)
		
// 	return (0);
// }

void	ft_test(int i)
{
	static 	t_mlxstore	MLX;
	int 	x;
	int 	y;

	(void)i;
	MLX.x = 449;
	MLX.y = 449;
	MLX.move = 100;
	MLX.size_x = 1000;
	MLX.size_y = 1000;
	MLX.color = 0x00FF6600;
	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, MLX.size_x, MLX.size_y, "Le putain de test");
	y = 449;
	while (++y < 550)
	{
		x = 449;
		while (++x < 550)
			mlx_pixel_put(MLX.mlx, MLX.win, x, y, MLX.color);
	}
	mlx_key_hook(MLX.win, my_fonct_key, &MLX);
	// mlx_mouse_hook(MLX.win, my_fonct_mouse, &MLX);
	mlx_loop(MLX.mlx);
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int main(int argc, char **argv)
{
	int		fd;
	char 	*line;

	if (argc != 2)
		ft_error("Pas le bon nombre d'argument");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	//ft_test(1);
	return (0);
}