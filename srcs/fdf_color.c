/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 02:46:48 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/02 02:46:50 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			put_color(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
			a->map[y][x].color = (localisation_color(a, a->map[y][x].z));
	}
}

void			ft_background(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
			ft_p_pixel_image(a, y, x, BACKGROUND);
	}
}

int				localisation_color(t_a *a, int z)
{
	double		r;

	r = a->e.distance_z / 10;
	if (z >= a->e.z_min && z < (a->e.z_min + (r * 1)))
		return (RED);
	else if (z >= (a->e.z_min + (r)) && z < (a->e.z_min + (r * 2)))
		return (ORANGE);
	else if (z >= (a->e.z_min + (r * 2)) && z < (a->e.z_min + (r * 3)))
		return (YELLOW);
	else if (z >= (a->e.z_min + (r * 3)) && z < (a->e.z_min + (r * 4)))
		return (LIMON);
	else if (z >= (a->e.z_min + (r * 4)) && z < (a->e.z_min + (r * 5)))
		return (RAZER);
	else if (z >= (a->e.z_min + (r * 5)) && z < (a->e.z_min + (r * 6)))
		return (WGREEN);
	else if (z >= (a->e.z_min + (r * 6)) && z < (a->e.z_min + (r * 7)))
		return (LAGON);
	else if (z >= (a->e.z_min + (r * 7)) && z < (a->e.z_min + (r * 8)))
		return (SKY);
	else if (z >= (a->e.z_min + (r * 8)) && z < (a->e.z_min + (r * 9)))
		return (BLUE_C);
	else if (z >= (a->e.z_min + (r * 9)) && z <= a->e.distance_z)
		return (BLUE);
	return (0xFFFFFF);
}

static void		ft_put_info_2(t_a *a)
{
	mlx_string_put(a->e.mlx, a->e.win, 1565, 100, 0xFFFFFF, a->e.str);
	a->e.str = "| Hauteur Moins  = Touche -/_     |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 120, 0xFFFFFF, a->e.str);
	a->e.str = "| Deplacement    = Touche < ^ > v |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 140, 0xFFFFFF, a->e.str);
	a->e.str = "| Changer l'ISO  = Touche T       |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 160, 0xFFFFFF, a->e.str);
	a->e.str = "| Intervertir Z  = Touche R       |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 180, 0xFFFFFF, a->e.str);
	a->e.str = "| Origine All    = Touche O       |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 200, 0xFFFFFF, a->e.str);
	a->e.str = "| Origine Z      = Touche Z       |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 220, 0xFFFFFF, a->e.str);
	a->e.str = "| Sortir du FDF  = Touche Esc     |";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 240, 0xFFFFFF, a->e.str);
	a->e.str = "-----------------------------------";
	mlx_string_put(a->e.mlx, a->e.win, 1565, 250, 0xFFFFFF, a->e.str);
}

void			ft_put_info(t_a *a)
{
	a->e.str = "Information touche I (on/off)";
	mlx_string_put(a->e.mlx, a->e.win, 1590, 5, RAZER, a->e.str);
	if (a->e.info > 0)
	{
		mlx_string_put(a->e.mlx, a->e.win, 20, 5, YELLOW, a->e.name);
		a->e.str = "-----------------------------------";
		mlx_string_put(a->e.mlx, a->e.win, 1565, 25, 0xFFFFFF, a->e.str);
		a->e.str = "| Zoom In        = Touche +       |";
		mlx_string_put(a->e.mlx, a->e.win, 1565, 40, 0xFFFFFF, a->e.str);
		a->e.str = "| Zoom Out       = Touche -       |";
		mlx_string_put(a->e.mlx, a->e.win, 1565, 60, 0xFFFFFF, a->e.str);
		a->e.str = "| Background     = Touche B       |";
		mlx_string_put(a->e.mlx, a->e.win, 1565, 80, 0xFFFFFF, a->e.str);
		a->e.str = "| Hauteur Plus   = Touche +/=     |";
		ft_put_info_2(a);
	}
}
