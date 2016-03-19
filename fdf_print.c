#include "fdf.h"

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void ft_print_map_to_image(t_all *all)
{
	int y;
	int x;
	int color;
	int color2;
	int i;

	color = 0xFFFFFF;
	y = -1;
	while (++y < all->env.max_line)
	{
		x = -1;
		while (++x < all->env.nb_caract)
		{
			if (all->map[y][x].z == 0)
				ft_put_pixel_to_image(all, y, x, color);
			else
				ft_put_pixel_to_image(all, y, x, 0xFF0000);
		}
	}
	mlx_put_image_to_window(all->env.mlx, all->env.win, all->env.img, all->env.origin_x, all->env.origin_y);
	i = mlx_destroy_image(all->env.mlx, all->env.img);
}
