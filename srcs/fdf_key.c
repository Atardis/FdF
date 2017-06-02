/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:26:51 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/04 13:26:53 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		reverse_z(t_a *a)
{
	int		y;
	int		x;

	a->e.touch_z *= -1;
	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
			a->map[y][x].z *= -1;
	}
	print(a);
}

static void		bonus_mineur(t_a *a, int keycode)
{
	if (keycode == B)
	{
		a->e.background *= -1;
		print(a);
	}
	else
	{
		a->e.iso *= -1;
		print(a);
	}
}

void			ft_info(t_a *a)
{
	a->e.info *= -1;
	print(a);
}

static void		origin_all(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	while (++y < a->e.max_y)
	{
		x = -1;
		while (++x < a->e.max_x)
		{
			a->map[y][x].x = x;
			a->map[y][x].y = y;
			a->map[y][x].z = a->map[y][x].zo;
		}
	}
	print(a);
}

int				my_fonct_key(int keycode, t_a *a)
{
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend", a);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		fdf_modif_pos(a, keycode);
	if (keycode == PLUS || keycode == MINUS)
		ft_modif_size(a, keycode);
	if (keycode == UNDER || keycode == EGAL)
		ft_modif_z(a, keycode);
	if (keycode == T || keycode == B)
		bonus_mineur(a, keycode);
	if (keycode == I)
		ft_info(a);
	if (keycode == R)
		reverse_z(a);
	if (keycode == O)
		origin_all(a);
	if (keycode == Z)
		origin_z(a);
	return (0);
}
