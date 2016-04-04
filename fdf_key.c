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

#include "fdf.h"

void		ft_error(char *str, t_a *a)
{
	ft_putendl(str);
	mlx_destroy_window(a->e.mlx, a->e.win);
	exit(1);
}

int				my_fonct_key(int keycode, t_a *a)
{
	ft_putnbr_end(keycode);
	if (keycode == EXIT)
		ft_error("ESC : Good Bye My Friend", a);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		fdf_modif_pos(a, keycode);
	if (keycode == PLUS || keycode == MINUS)
		ft_modif_size(a, keycode);
	if (keycode == B)
		background_print(a);
	if (keycode == UNDER || keycode == EGAL)
		ft_modif_z(a, keycode);
	if (keycode == I)
		info_print(a);
	if (keycode == T)
		iso_print(a);
	return (0);
}

void			background_print(t_a *a)
{
	a->e.background *= -1;
	print(a);
}

void			iso_print(t_a *a)
{
	a->e.iso *= -1;
	print(a);
}

void			info_print(t_a *a)
{
	a->e.info *= -1;
	print(a);
}