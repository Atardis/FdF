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

void ft_print_map_to_image(t_a *a)
{
	int y;
	int x;
	int color;
	int color2;
	int i;

	color = 0xFFFFFF;
	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if (a->map[y][x].z == 0)
				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, color);
			else
				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFF0000);
		}
	}
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	i = mlx_destroy_image(a->e.mlx, a->e.img);
}

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
			ft_putendl("while 1");
			ft_putstr("x origine ->");
			ft_putnbr_end(a->map[y][x].x);
			ft_putstr("y origine ->");
			ft_putnbr_end(a->map[y][x].y);
			if ((i = recover_point_line(a, x, y)) > 0)
				line_tracer(a);
			else
				ft_put_pixel_to_image(a, a->map[y][x].y, a->map[y][x].x, 0xFFFFFF);

			ft_putstr("ce que renvoie le recover_point_line  ->");
			ft_putnbr_end(i);
		}
	}
	ft_putendl("fin de boucle bresenham");
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	mlx_destroy_image(a->e.mlx, a->e.img);
}


int			recover_point_line(t_a *a, int x, int y)
{
	int X;

	X = 1 + x;
	if (x < a->e.nb_caract && X < a->e.nb_caract)
	{
		a->p1.x = x;
		a->p1.y = y;
		a->p1.c = 0xFFFFFF;
		a->p2.x = X;
		a->p2.y = y;
		a->p2.c = 0xFFFFFF;
		
		ft_putnbr(a->p1.x);
		ft_putstr("  ");
		ft_putnbr_end(a->p1.y);
		ft_putnbr(a->p2.x);
		ft_putstr("  ");
		ft_putnbr_end(a->p2.y);
		ft_putstr(" \n");
	}
	else
		return (0);
	return (1);
}

// int			recover_point_column(t_a *a, int x, int y)
// {
// 	int X;
// 	int Y;

// 	if (a->map[y][x] && a->map[++y][x])
// 	{
		
// 	}
// 	return (1);
// }

void		line_tracer(t_a *a)
{
	int i;
	int dx;
	int dy;
	int	xinc;
	int	yinc;
	int x;
	int y;
	int	tmp;

	i = 0;
	x = a->p1.x * 2;
	y = a->p1.y * 2;
	dx = a->p2.x * 2 - x;
	dy = a->p2.y * 2 - y;
	xinc = (dx > 0) ? 1 : -1 ;
	yinc = (dy > 0) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	ft_put_pixel_to_image(a, x, y, 0xFFFFFF);
	i = 1;
	if (dx > dy)
	{
		tmp = dx / 2;
		for (i = 1 ; i <= dx ; i++)
		{
			x += xinc ;
			tmp += dy ;
			if (tmp >= dx)
			{
				tmp -= dx;
				y += yinc ;
			}
			ft_put_pixel_to_image(a, x, y, 0xFFFFFF);
			i = 1;
		}
	}
	else
	{
		tmp = dy / 2 ;
		for (i = 1 ; i <= dy ; i++)
		{
			y += yinc ;
			tmp += dx ;
			if (tmp >= dy)
			{
				tmp -= dy ;
				x += xinc ;
			}
			ft_put_pixel_to_image(a, x, y, 0xFFFFFF);
		}
	}
}