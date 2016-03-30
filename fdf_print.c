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

static void		ft_print_map(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			ft_putnbr(a->map[y][x].x);
			ft_putchar(':');
			ft_putnbr(a->map[y][x].y);
			if (y < a->e.max_line - 1)
				ft_putstr("   ");
			else
				ft_putstr("  ");
		}
		ft_putchar('\n');
	}
}

void		ft_print_to_image_bresenham(t_a *a)
{
	int y;
	int x;

	y = -1;
	while (++y < a->e.max_line)
	{
		x = -1;
		while (++x < a->e.nb_caract)
		{
			if ((recover_point(a, x, y, 'x')) > 0)
				ligne(a);
			if ((recover_point(a, x, y, 'y')) > 0)
				ligne(a);
		}
	}
	//ft_print_map(a);
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	mlx_destroy_image(a->e.mlx, a->e.img);
}

int			recover_point(t_a *a, int x, int y, char c)
{
	int X;
	int Y;

	X = 1 + x;
	Y = 1 + y;
	if (x < a->e.nb_caract && X < a->e.nb_caract && c == 'x' && x >= 0)
	{
		a->p1.x = a->map[y][x].x;
		a->p1.y = a->map[y][x].y;
		a->p2.x = a->map[y][X].x;
		a->p2.y = a->map[y][X].y;
		return (1);
	}
	if (y < a->e.max_line && Y < a->e.max_line && c == 'y' && y >= 0)
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
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
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
