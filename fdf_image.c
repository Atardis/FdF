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

void	fdf_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, MAX_X, MAX_Y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_error("probleme get_data", a);
	a->e.bpp /= 8;
	if (a->e.background < 0)
		ft_background(a);
}
