/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 07:29:15 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 07:29:17 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_modif_up(t_all *all)
{
	int i;

	all->env.origin_y -= 10;
	i = mlx_destroy_image(all->env.mlx, all->env.img);
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.width, all->env.height);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	ft_print_map_to_image(all);
}

void	ft_modif_down(t_all *all)
{
	int i;

	all->env.origin_y += 10;
	i = mlx_destroy_image(all->env.mlx, all->env.img);
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.width, all->env.height);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	ft_print_map_to_image(all);
}

void	ft_modif_left(t_all *all)
{
	int i;

	all->env.origin_x -= 10;
	i = mlx_destroy_image(all->env.mlx, all->env.img);
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.width, all->env.height);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	ft_print_map_to_image(all);
}

void	ft_modif_right(t_all *all)
{
	int i;

	all->env.origin_x += 10;
	i = mlx_destroy_image(all->env.mlx, all->env.img);
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.width, all->env.height);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	ft_print_map_to_image(all);
}

int	count_carac(char *line)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (line[index] == '-' || (line[index] >= '0' && line[index] <= '9'))
		{
			count++;
			while (line[index] && line[index] != ' ')
				index++;
		}
		else
			index++;
	}
	return (count);
}

t_map	**fonction_creat_struct(t_all *all)
{
	unsigned int y;
	int x;

	if (!(all->map = (t_map **)malloc(sizeof(t_map *) * all->env.max_line)))
		ft_error("Malloc has Failed for the struct Y");
	y = -1;
	while (++y < all->env.max_line)
	{
		if (!(all->map[y] = (t_map *)malloc(sizeof(t_map) * all->env.nb_caract)))
			ft_error("Malloc has Failed for the struct X");
			x = -1;
		while (++x < all->env.nb_caract)
		{
			all->map[y][x].z = 0;
			all->map[y][x].y = y;
			all->map[y][x].x = x;
			all->map[y][x].color = 0;
		}
	}
	return(all->map);
}

void		send_map_to_struct(t_all all, char *str, int y)
{
	int i;
	int x;
	int find;

	i = 0;
	find = 0;
	x = 0;
	while (str[i] && y < all.env.max_line)
	{
		while (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while ((str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) && find == 0 &&
			x < all.env.nb_caract)
		{
			find = 1;
			all.map[y][x].z = ft_atoi_re(str, i);
			x++;
		}
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'A' && str[i] <= 'F') || str[i] == ',' || str[i] == 'x'))
			i++;
		find = 0;
	}
}

void		ft_print_struct(t_map **map, int max_line, int nb_caract)
{
	int y;
	int x;

	y = -1;
	while (++y < max_line)
	{
		x = -1;
		while (++x < nb_caract)
		{
			ft_putnbr(map[y][x].z);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void ft_print_map_to_image(t_all *all)
{
	int y;
	int x;
	int color;
	int color2;

	color = 0xFF0000;
	color2 = 0xFFFFFF;
	y = -1;
	while (++y < all->env.max_line)
	{
		x = -1;
		while (++x < all->env.nb_caract)
		{
			if (all->map[y][x].z == 0)
				ft_put_pixel_to_image(all, y, x, color2);
			else
				ft_put_pixel_to_image(all, y, x, color);
		}
	}
	mlx_put_image_to_window(all->env.mlx, all->env.win, all->env.img, all->env.origin_x, all->env.origin_y);
}
