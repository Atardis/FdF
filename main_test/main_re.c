#include "../libft/includes/libft.h"
#include <mlx.h>

int main(void)
{
	int i;
	unsigned int j;
	char *str;
	void *mlx;
	void *win;
	void *image;

	str = "12722176";
	j = atoi(str);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "");
	image = mlx_new_image(mlx, 500, 500);
	ft_putchar('\n');
	i = -1;
	while (++i < 500)
		mlx_pixel_put(mlx, win, 250, i, j);
	mlx_loop(mlx);
	return(0);
}
