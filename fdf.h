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
#include <fcntl.h>

#define BUFF_SIZE 1000
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define MOUSE_UP 4

#define GREEN 9
#define BLUE 11
#define RED
#define EXIT 53

typedef struct	s_mlxstore
{
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	int 	move;
	int 	size_y;
	int 	size_x;
	int		color;
}				t_mlxstore;

void	color(int keycode, t_mlxstore *MLX);
void	ft_up(int keycode, t_mlxstore *MLX);
void	ft_down(int keycode, t_mlxstore *MLX);
void	ft_right(int keycode, t_mlxstore *MLX);
void	ft_left(int keycode, t_mlxstore *MLX);
void	ft_zoom_up(int keycode, t_mlxstore *MLX);
void	ft_zoom_down(int keycode, t_mlxstore *MLX);

#endif
