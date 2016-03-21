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

void	ft_modif_plus(t_a *a)
{
	int i;
	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl,
			&a->e.ed);
	a->e.bpp /= 8;
	i = a->e.space;
	i += 1;
	if (i >= 0)
		a->e.space += 1;
	else
		a->e.space = 1;
	ft_print_map_to_image(a);
}

void	ft_modif_minus(t_a *a)
{
	int i;

	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl,
			&a->e.ed);
	a->e.bpp /= 8;
	i = a->e.space;
	i -= 1;
	if (i >= 0)
		a->e.space -= 1;
	else
		a->e.space = 1;
	ft_print_map_to_image(a);
}

void	ft_modif_up(t_a *a)
{
	int i;

	a->e.origin_y -= 10;
	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	a->e.bpp /= 8;
	if (a->e.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(a);
}

void	ft_modif_down(t_a *a)
{
	int i;

	a->e.origin_y += 10;
	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl,
			&a->e.ed);
			a->e.bpp /= 8;
	if (a->e.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(a);
}

void	ft_modif_left(t_a *a)
{
	int i;

	a->e.origin_x -= 10;
	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl,
			&a->e.ed);
			a->e.bpp /= 8;
	if (a->e.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(a);
}

void	ft_modif_right(t_a *a)
{
	int i;

	a->e.origin_x += 10;
	mlx_clear_window(a->e.mlx, a->e.win);
	a->e.img = mlx_new_image(a->e.mlx, a->e.size_x, a->e.size_y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl,
			&a->e.ed);
			a->e.bpp /= 8;
	if (a->e.data == NULL)
		ft_error("probleme get_data");
	ft_print_map_to_image(a);
}
