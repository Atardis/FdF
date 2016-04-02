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

void move_map(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			a->map[y][x].x -= (a->e.move_x);
			a->map[y][x].y -= (a->e.move_y);
		}
	}
}

void		ft_print_to_image_bresenham(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			if ((recover_point(a, x, y, 'x')) > 0)
			{
				if (a->map[y][x].z < a->map[y][x + 1].z)
					ligne(a , a->map[y][x + 1].color);
				else if (a->map[y][x].z > a->map[y][x + 1].z || a->map[y][x].z == a->map[y][x + 1].z)
					ligne(a , a->map[y][x].color);
			}
			if ((recover_point(a, x, y, 'y')) > 0)
			{
				if (a->map[y][x].z < a->map[y + 1][x].z)
					ligne(a , a->map[y + 1][x].color);
				else if (a->map[y][x].z > a->map[y + 1][x].z || a->map[y][x].z == a->map[y + 1][x].z)
					ligne(a , a->map[y][x].color);
			}
		}
	}
	fdf_recover_size(a);
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	ft_put_info(a);
	mlx_destroy_image(a->e.mlx, a->e.img);
}

int			recover_point(t_a *a, int x, int y, char c)
{
	int X;
	int Y;

	X = 1 + x;
	Y = 1 + y;
	if (x < a->e.max_x && X < a->e.max_x && c == 'x' && x >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 2) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[y][X].x - ((a->map[y][X].y / 2) * a->e.iso);
		a->p2.y = a->map[y][X].y - a->map[y][X].z;
		return (1);
	}
	if (y < a->e.max_y && Y < a->e.max_y && c == 'y' && y >= 0)
	{
		a->p1.x = a->map[y][x].x - ((a->map[y][x].y / 2) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[Y][x].x - ((a->map[Y][x].y / 2) * a->e.iso);
		a->p2.y = a->map[Y][x].y - a->map[Y][x].z;
		return (1);
	}
	return (0);
}

void ligne(t_a *a, int	color)
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
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	ft_put_pixel_to_image(a, y, x, color);
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
			ft_put_pixel_to_image(a, y, x, color);
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
      		ft_put_pixel_to_image(a, y, x, color);
	  	}
	}
}
