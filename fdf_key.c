/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:52:56 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/19 13:53:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_modif_up(t_all *all)
{
	int i;

	all->env.origin_y -= 10;
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl, &all->env.ed);
	all->env.bpp /= 8;
	if (all->env.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(all);
}

void	ft_modif_plus(t_all *all)
{
	int i;
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	all->env.bpp /= 8;
	i = all->env.space;
	i += 1;
	if (i >= 0)
		all->env.space += 1;
	else
		all->env.space = 1;
	ft_print_map_to_image(all);
}

void	ft_modif_minus(t_all *all)
{
	int i;

	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
	all->env.bpp /= 8;
	i = all->env.space;
	i -= 1;
	if (i >= 0)
		all->env.space -= 1;
	else
		all->env.space = 1;
	ft_print_map_to_image(all);
}

void	ft_modif_down(t_all *all)
{
	int i;

	all->env.origin_y += 10;
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
			all->env.bpp /= 8;
	if (all->env.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(all);
}

void	ft_modif_left(t_all *all)
{
	int i;

	all->env.origin_x -= 10;
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
			all->env.bpp /= 8;
	if (all->env.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(all);
}

void	ft_modif_right(t_all *all)
{
	int i;

	all->env.origin_x += 10;
	mlx_clear_window(all->env.mlx, all->env.win);
	all->env.img = mlx_new_image(all->env.mlx, all->env.size_x, all->env.size_y);
	all->env.data = mlx_get_data_addr(all->env.img, &all->env.bpp, &all->env.sl,
			&all->env.ed);
			all->env.bpp /= 8;
	if (all->env.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(all);
}
