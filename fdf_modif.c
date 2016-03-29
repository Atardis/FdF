/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:11:21 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/21 21:11:24 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fdf_modif_pos(t_a *a, int keycode)
{
  int y;
  int x;

  y = -1;
  while (++y < a->e.max_line)
  {
    x = -1;
    while (++x < a->e.nb_caract)
	{
		if (keycode == LEFT)
			a->map[y][x].x -= 10;
		else if (keycode == RIGHT)
			a->map[y][x].x += 10;
		else if (keycode == UP)
			a->map[y][x].y -= 10;
		else if (keycode == DOWN)
			a->map[y][x].y += 10;
	}
  }
  fdf_new_image(a);
  ft_print_to_image_bresenham(a);
}

void	ft_modif_size(t_a *a, int keycode)
{
	int x;
	int y;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (keycode == PLUS)
			{
				a->map[y][x].x *= 1.1;
				a->map[y][x].y *= 1.1;
			}
			else
			{
				a->map[y][x].x /= 1.1;
				a->map[y][x].y /= 1.1;
			}
		}
	}
	mlx_clear_window(a->e.mlx, a->e.win);
	fdf_new_image(a);
	ft_print_to_image_bresenham(a);
}

void fdf_new_image(t_a *a)
{
  a->e.img = mlx_new_image(a->e.mlx, a->e.size, a->e.size);
  a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
  if (a->e.data == NULL)
  	ft_error("probleme get_data");
}
