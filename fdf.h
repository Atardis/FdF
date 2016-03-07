/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 01:42:23 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/05 01:42:25 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include <mlx.h>

#define BUFF_SIZE 600
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define EXIT 53

typedef struct	s_mlxstore
{
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	int 	move;
}				t_mlxstore;

void	ft_up(int keycode, t_mlxstore *MLX);
void	ft_down(int keycode, t_mlxstore *MLX);
void	ft_right(int keycode, t_mlxstore *MLX);
void	ft_left(int keycode, t_mlxstore *MLX);



#endif
