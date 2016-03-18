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

void	define_struct(t_mlxstore *mlx)
{
	mlx->size_x = 1000;
	mlx->size_y = 1000;
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		my_fonct_key(int keycode, t_mlxstore *mlx)
{
	ft_putnbr_end(keycode);
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend");
	return (0);
}

int main(int argc, char **argv)
{
	t_mlxstore	mlx;
	t_fdfpoint	**mlxmap;
	char 	*line;
	int		y;
	int 	i;

	define_struct(&mlx);
	if (argc < 2)
		ft_error("Pas le bon nombre d'argument");
	if ((mlx.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	mlx.max_line = 0;
	mlx.nb_caract = 0;
	while (get_next_line(mlx.fd, &line) > 0)
	{
		if (mlx.max_line == 0)
			mlx.nb_caract = count_carac(line);
		if (mlx.max_line != 0)
			if (mlx.nb_caract != count_carac(line))
				ft_error("Fichier Invalide");
		mlx.max_line++;
	}
	close(mlx.fd);
	mlxmap = fonction_creat_struct(mlxmap, mlx.max_line, mlx.nb_caract);
	if ((mlx.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant");
	y = -1;
	i = 0;
	while ((i = get_next_line(mlx.fd, &line)) > 0 && ++y < mlx.max_line)
		send_map_to_struct(mlxmap, line, y, mlx);
	ft_print_struct(mlxmap, mlx.max_line, mlx.nb_caract);
	return (0);
}

	// mlx_key_hook(mlx.win, my_fonct_key, &mlx);
	// mlx_loop(mlx.mlx);
