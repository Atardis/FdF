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

void ft_put_pixel_to_image(t_env *env, int y, int x, int color)
{
	int i;
	int j;

	j = 10;
	i = 10;
	if (x < 0 || x > env->width || y < 0 || y > env->height)
		ft_error("probleme de put_pixel");
	*(unsigned int*)(env->data + ((i + x) * 15) * env->bpp + ((j + y) * 15) * env->sl) = mlx_get_color_value(env->mlx, color);
}


void init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
	  ft_error("initialisation mlx_init error");
	if (!(env->win = mlx_new_window(env->mlx, env->width, env->height, "Yolo")))
		ft_error("initialisation mlx_new_windows error");
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->ed);
	env->bpp /= 8;
}

int main(int argc, char **argv)
{
	t_mlxstore	mlx;
	t_fdfpoint	**mlxmap;
	t_env				env;
	char 	*line;
	int		y;
	int 	i;

	env.width = 1000;
	env.height = 1000;
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
	init(&env);
	ft_print_map_to_image(&env, mlxmap, &mlx);
	mlx_loop(env.mlx);
	return (0);
}
