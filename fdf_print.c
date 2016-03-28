/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:17:18 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/21 13:17:20 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

// void ft_print_map_to_image(t_a *a)
// {
// 	int y;
// 	int x;
// 	int color;
// 	int color2;
// 	int i;

// 	color = 0xFFFFFF;
// 	y = -1;
// 	while (++y < a->e.max_line)
// 	{
// 		x = -1;
// 		while (++x < a->e.nb_caract)
// 		{
// 			if (a->map[y][x].z == 0)
// 				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, color);
// 			else
// 				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFF0000);
// 		}
// 	}
// 	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
// 	i = mlx_destroy_image(a->e.mlx, a->e.img);
// }

// void		ft_print_to_image(t_a *a)
// {
// 	int y;
// 	int x;

// 	y = -1;
// 	while (++y < a->e.max_line)
// 	{
// 		x = -1;
// 		while (++x < a->e.nb_caract)
// 		{
// 			if (a->map[y][x].z == 0)
// 				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFFFFFF);
// 			else
// 				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFF0000);
// 		}
// 	}
// 	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
// 	mlx_destroy_image(a->e.mlx, a->e.img);
// }

void		ft_print_to_image_bresenham(t_a *a)
{
	int y;
	int x;
	int i;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x <= a->e.nb_caract)
		{
			if ((i = recover_point_line(a, x, y)) > 0)
				ligne(a);
			if ((i = recover_point_column(a, x, y)) > 0)
				ligne(a);
			ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	mlx_destroy_image(a->e.mlx, a->e.img);
}


int			recover_point_line(t_a *a, int x, int y)
{
	int X;

	X = 1 + x;
	if (x < a->e.nb_caract && X < a->e.nb_caract)
	{
		a->p1.x = a->map[y][x].x;
		a->p1.y = a->map[y][x].y;
		a->p2.x = a->map[y][X].x;
		a->p2.y = a->map[y][X].y;
		return (1);
	}
	return (0);
}

int			recover_point_column(t_a *a, int x, int y)
{
	int Y;

	Y = 1 + y;
	if (y < a->e.max_line && Y < a->e.max_line)
	{
		a->p1.x = a->map[y][x].x;
		a->p1.y = a->map[y][x].y;
		a->p2.x = a->map[Y][x].x;
		a->p2.y = a->map[Y][x].y;
		return (1);
	}
	return (0);
}

void ligne(t_a *a)
{
	int dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	x = a->p1.x ;
	y = a->p1.y ;
	dx = a->p2.x - a->p1.x;
	dy = a->p2.y - a->p1.y;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	ft_put_pixel_to_image(a, y, x, 0xFF0000);
	if ( dx > dy )
	{
		cumul = dx / 2;
		for (i = 1 ; i <= dx ; i++)
		{
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) 
			{
				cumul -= dx ;
				y += yinc ;
			}
			ft_put_pixel_to_image(a, y, x, 0xFF0000) ;
		}
	}
	else
	{
		cumul = dy / 2 ;
		for (i = 1 ; i <= dy ; i++)
		{
			y += yinc ;
			cumul += dx ;
			if (cumul >= dy)
			{
				cumul -= dy ;
				x += xinc;
			}
      		ft_put_pixel_to_image(a, y, x, 0xFF0000);
	  	}
	}
}
