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
	MLX.win = mlx_new_window(MLX.mlx, 1000, 1000, "Le putain de test");
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

void		ft_error(char *str)
{
	ft_putendl(str);
}

int main(int argc, char **argv)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	int		read_result;
	char 	*line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("error");
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	ft_test(1);
	return (0);
}