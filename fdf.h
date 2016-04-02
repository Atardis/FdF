/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 01:42:23 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/02 03:30:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <math.h>

#define EXIT 53
#define BUFF_SIZE 600
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define PLUS 69
#define MINUS 78
#define M 46
#define N 45
#define B 11
#define EGAL 24
#define UNDER 27
#define I 34
#define T 17

#define BLUE 0x0901F7
#define BLUE_C 0x015BF7
#define SKY 0x01B5F7
#define LAGON 0x33AB9B
#define WGREEN 0x01F79D
#define RAZER 0x01F74B
#define LIMON 0xADF701
#define YELLOW 0xEFF701
#define ORANGE 0xF78C01
#define RED 0xFE4D01
#define BACKGROUND 0x6B4E13

typedef struct		s_fdfstore
{
	double			x;
	double			y;
	double			z;
	double			zo;
	int 			color;
}					t_map;

typedef struct		s_environ
{
	void 				*mlx;
	void 				*win;
	void 				*img;

	char 				*data;

	int 				fd;
	int					width;
	int					height;
	int 				size;
	int					bpp;
	int 				sl;
	int 				ed;
	int					origin_x;
	int					origin_y;
	int 				space;
	unsigned 		max_y;
	unsigned 		max_x;
	int					iso;

	double				size_x;
	double				size_y;
	double				size_X;
	double				size_Y;
	double				move_x;
	double				move_y;
	double				z_max;
	double				z_min;
	double				distance_z;
	int						background;
	int						info;
	int						tmp;
}					t_env;

typedef struct 		s_trace
{
	int				x;
	int 			y;
	int				c;
}					t_p;

typedef struct 		s_all
{
	t_map			**map;
	t_env			e;
	t_p				p1;
	t_p				p2;
} 					t_a;



void		define_struct(t_a *a);
void		ft_error(char *str, t_a *a);
void 		ft_put_pixel_to_image(t_a *a, int y, int x, int color);
void 		init_mxl(t_a *a);
void		send_map_to_struct(t_a *a, char *str, int y);
int			my_fonct_key(int keycode, t_a *a);
void		ft_modif_up(t_a *a);
void		ft_modif_down(t_a *a);
void		ft_modif_left(t_a *a);
void		ft_modif_right(t_a *a);
void		ft_modif_plus(t_a *a);
void		ft_modif_minus(t_a *a);
void		define_struct(t_a *a);

void		fdf_modif_pos(t_a *a, int keycode);
void		ft_modif_size(t_a *a, int keycode);
void		fdf_new_image(t_a *a);

void		ft_print_to_image_bresenham(t_a *a);
int			recover_point(t_a *a, int x, int y, char c);
void 		ligne(t_a *a, int	color);
void 		fdf_recover_size(t_a *a);
void 		fdf_recover_size_o(t_a *a);
void move_map(t_a *a);
void size_z_max_min(t_a *a);
void size_max_z_to_min_z(t_a *a);
int	localisation_color(t_a *a, int z);
void put_color(t_a *a);
void ft_background(t_a *a);
void ft_modif_z(t_a *a, int keycode);

void ft_put_info(t_a *a);
void print(t_a *a);
double			distance(t_a *a);
void iso_modif(t_a *a);



int		my_fonct_key(int keycode, t_a *a);
int	count_carac(char *line);

t_map	**fonction_creat_struct(t_a *a);

#endif
