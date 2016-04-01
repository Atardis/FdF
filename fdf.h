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
	int					zoom_in;
	int 				zoom_out;
	unsigned 		max_line;
	unsigned 		nb_caract;

	double				size_x;
	double				size_y;
	double				size_X;
	double				size_Y;
	double				move_x;
	double				move_y;
	double				z_max;
	double				z_min;
	double				distance_z;
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
void		ft_error(char *str);
void 		ft_put_pixel_to_image(t_a *a, int y, int x, int color);
void 		init_mxl(t_a *a);
void		send_map_to_struct(t_a *a, char *str, int y);
void		ft_print_struct(t_map **map, int max_line, int nb_caract);
void 		ft_print_map_to_image(t_a *a);
int			my_fonct_key(int keycode, t_a *a);
void		ft_modif_up(t_a *a);
void		ft_modif_down(t_a *a);
void		ft_modif_left(t_a *a);
void		ft_modif_right(t_a *a);
void		ft_error(char *str);
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




int		my_fonct_key(int keycode, t_a *a);
int	count_carac(char *line);

t_map	**fonction_creat_struct(t_a *a);

#endif
