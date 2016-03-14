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

void	ft_exit(void)
{
	ft_putchar('\n');
	ft_putendl("ESC : Good Bye My Friend");
	exit(1);
}

void	define_struct(t_mlxstore *mlx)
{
	mlx->x = 449;
	mlx->y = 449;
	mlx->move = 100;
	mlx->size_x = 1000;
	mlx->size_y = 1000;
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(2);
}

int main(int argc, char **argv)
{
	static 	t_mlxstore	mlx;
	static 	t_fdfpoint	**mlxmap;
	int		fd;
	char 	*line;
	int		y;
	int		max_line;
	int 	nb_caract;

	define_struct(&mlx);
	if (argc != 2)
		ft_error("Pas le bon nombre d'argument");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	max_line = 0;
	nb_caract = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (max_line == 0)
			nb_caract = count_space(line);
		if (max_line != 0)
			if (nb_caract != count_space(line))
				ft_error("Fichier Invalide");
		max_line++;
	}
	close(fd);
	mlxmap = fonction_creat_struct(mlxmap, max_line, nb_caract);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = -1;
	while (get_next_line(fd, &line) > 0 && ++y < max_line)
		send_map_to_struct(mlxmap, line, y, nb_caract);
	ft_print_struct(mlxmap, max_line, nb_caract);
	return (0);
}













	// mlx.mlx = mlx_init();
	// mlx.win = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "");
	// mlx_key_hook(mlx.win, my_fonct_key, &mlx);
	// mlx_loop(mlx.mlx);