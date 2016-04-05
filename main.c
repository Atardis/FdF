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

void					print(t_a *a)
{
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

static void				verif_gnl(t_a *a, char	**line)
{
	free(*line);
	if (a->e.tmp == -1)
		ft_error("Probleme de Lecture / Pas bon fichier donné", a);
	if (a->e.max_y == 0 || a->e.max_x == 0)
		ft_error("fichier Vide", a);
}

static void				read_file(t_a *a, char *str, int y, int i)
{
	char				*line;

	line = NULL;
	while ((a->e.tmp = get_next_line(a->e.fd, &line)) > 0)
	{
		if (a->e.max_y == 0)
			a->e.max_x = count_carac(line);
		if (a->e.max_y != 0)
			if (a->e.max_x != (int)count_carac(line))
				ft_error("Fichier Invalide", a);
		a->e.max_y++;
		free(line);
	}
	verif_gnl(a, &line);
	close(a->e.fd);
	a->map = fonction_creat_struct(a);
	if ((a->e.fd = open(str, O_RDONLY)) == -1)
		ft_error("Fichier Inexistant / Pas les Droits", a);
	y = -1;
	i = 0;
	while ((i = get_next_line(a->e.fd, &line)) > 0 && ++y < a->e.max_y)
	{
		send_map_to_struct(a, line, y);
		free(line);
	}
	verif_gnl(a, &line);
}

int						main(int argc, char **argv)
{
	t_a					a;
	int					y;
	int					i;

	init(&a);
	if (argc < 2)
		ft_error("Pas le bon nombre d'argument", &a);
	if ((a.e.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Fichier Inexistant / Pas les Droits", &a);
	i = 0;
	y = 0;
	read_file(&a, argv[1], y, i);
	while(1);
	// size_z_max_min(&a);
	// ft_print_to_image_bresenham(&a);
	// mlx_hook(a.e.win, 2, (1L << 01), my_fonct_key, &a);
	// mlx_loop(a.e.mlx);
	return (0);
}
