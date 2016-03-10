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
	ft_putendl("--------------");
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

void	define_struct(t_mlxstore *MLX)
{
	MLX->x = 449;
	MLX->y = 449;
	MLX->move = 100;
	MLX->size_x = 1000;
	MLX->size_y = 1000;
	MLX->color = 0x00FF6600;
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int main(int argc, char **argv)
{
	static 	t_mlxstore	MLX;
	int		fd;
	char 	*line;
	int		y;

	define_struct(&MLX);
	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, MLX.size_x, MLX.size_y, "Mon Test Fdf");
	if (argc != 2)
		ft_error("Pas le bon nombre d'argument");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = 15;
	while (get_next_line(fd, &line) > 0)
	{
		print_map_to_win(&MLX, line, y);
		y = y + 15;
	}
	mlx_key_hook(MLX.win, my_fonct_key, &MLX);
	mlx_loop(MLX.mlx);
	return (0);
}