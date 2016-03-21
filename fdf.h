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

#define EXIT 53
#define BUFF_SIZE 600
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define PLUS 69
#define MINUS 78

typedef struct	s_fdfstore
{
	double			x;
	double			y;
	double			z;
	int 	color;
}				t_map;

typedef struct	s_environ
{
	void 		*mlx;
	void 		*win;
	void 		*img;
	char 		*data;
	int 			fd;
	int				width;
	int				height;
	int 			size_y;
	int 			size_x;
	int				bpp;
	int 			sl;
	int 			ed;
	int				origin_x;
	int				origin_y;
	int 			space;
	unsigned 	max_line;
	unsigned 	nb_caract;
}						t_env;

typedef struct s_all
{
	t_map		**map;
	t_env		e;
} 				t_a;

void		define_struct(t_a *a);
void		ft_error(char *str);
void 		ft_put_pixel_to_image(t_a *a, int y, int x, int color);
void 		init(t_a *a);
void		send_map_to_struct(t_a all, char *str, int y);
void		ft_print_struct(t_map **map, int max_line, int nb_caract);
void 		ft_print_map_to_image(t_a *a);
int		my_fonct_key(int keycode, t_a *a);
void	ft_modif_up(t_a *a);
void	ft_modif_down(t_a *a);
void	ft_modif_left(t_a *a);
void	ft_modif_right(t_a *a);
void		ft_error(char *str);
void	ft_modif_plus(t_a *a);
void	ft_modif_minus(t_a *a);
void	define_struct(t_a *a);

void fdf_modif_left(t_a *a);
void fdf_modif_up(t_a *a);
void fdf_modif_right(t_a *a);
void fdf_modif_down(t_a *a);
void fdf_new_image(t_a *a);




int		my_fonct_key(int keycode, t_a *a);
int	count_carac(char *line);

t_map	**fonction_creat_struct(t_a *a);

#endif
