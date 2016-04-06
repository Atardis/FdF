/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:33:50 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/04 13:33:52 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *str, t_a *a)
{
	a->e.tmp = 0;
	ft_putendl(str);
	if (a->map != NULL && a->e.verif != 0)
	{
		mlx_clear_window(a->e.mlx, a->e.win);
		mlx_destroy_window(a->e.mlx, a->e.win);
		free(a->e.mlx);
		free(a->map);
	}
	exit(1);
}

void		fdf_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, MAX_X, MAX_Y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_error("Problem of Get_Data", a);
	a->e.bpp /= 8;
	if (a->e.background < 0)
		ft_background(a);
}

void		ft_p_pixel_image(t_a *a, int y, int x, int color)
{
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
		*(unsigned int*)(a->e.data + (x * (a->e.bpp)) + (y * a->e.sl)) = color;
}

void		init(t_a *a)
{
	if (!(a->e.mlx = mlx_init()))
		ft_error("initialisation mlx_init error", a);
	if (!(a->e.win = mlx_new_window(a->e.mlx, MAX_X, MAX_Y, "FDF")))
		ft_error("initialisation mlx_new_windows error", a);
	a->e.background = 1;
	a->e.info = -1;
	a->e.iso = -1;
	fdf_new_image(a);
}
