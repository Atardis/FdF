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

void fdf_modif_left(t_a *a)
{
  int y;
  int x;
  int i;

  y = -1;
  while (++y < a->e.max_line)
  {
    x = -1;
    while (++x < a->e.nb_caract)
		a->map[y][x].x -= 10;
  }
  fdf_new_image(a);
  ft_print_map_to_image(a);
}

void fdf_modif_right(t_a *a)
{
  int y;
  int x;

  y = -1;
  while (++y < a->e.max_line)
  {
    x = -1;
    while (++x < a->e.nb_caract)
		a->map[y][x].x += 10;  
  }
  fdf_new_image(a);
  ft_print_map_to_image(a);
}

void fdf_modif_up(t_a *a)
{
  int y;
  int x;

  y = -1;
  while (++y < a->e.max_line)
  {
    x = -1;
    while (++x < a->e.nb_caract)
		a->map[y][x].y -= 10;

  }
  fdf_new_image(a);
  ft_print_map_to_image(a);
}

void fdf_modif_down(t_a *a)
{
  int y;
  int x;

	y = -1;
  while (++y < a->e.max_line)
  {
    x = -1;
    while (++x < a->e.nb_caract)
		a->map[y][x].y += 10;
  }
  fdf_new_image(a);
  ft_print_map_to_image(a);
}

void fdf_new_image(t_a *a)
{
  a->e.img = mlx_new_image(a->e.mlx, a->e.size, a->e.size);
  a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
  a->e.bpp /= 8;
  if (a->e.data == NULL)
  	ft_error("probleme get_data");
}
