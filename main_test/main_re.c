// #include "../libft/includes/libft.h"
// #include <mlx.h>
//
// int main(void)
// {
// 	int i;
// 	unsigned int j;
// 	char *str;
// 	void *mlx;
// 	void *win;
// 	void *image;
//
// 	str = "12722176";
// 	j = atoi(str);
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "");
// 	image = mlx_new_image(mlx, 500, 500);
// 	ft_putchar('\n');
// 	i = -1;
// 	while (++i < 500)
// 		mlx_pixel_put(mlx, win, 250, i, j);
// 	mlx_loop(mlx);
// 	return(0);
// }

#include <mlx.h>
#include <stdio.h>

#define WIDTH 1200
#define HEIGHT 800


int       main()
{
  void  *mlx_ptr;
  void  *win_ptr;
  void	*img;
  char	*data;
  int	bpp;
  int	sl;
  int	ed;
  int	x;
  int	y;
  int	i;
  int	j;

  x = 100;
  y = 142;
  i = -1;
  j = -1;
  if (!(mlx_ptr = mlx_init()))
	  return (0);
  win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fenetre de Astaroth");
  img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
  data = mlx_get_data_addr(img, &bpp, &sl, &ed);
  bpp /= 8;
  printf("bpp: %d, sl: %d, ed: %d\n", bpp, sl, ed);
  while (++i < 60)
  {
	  while (++j < 60)
  		*(unsigned int*)(data + (x + j) * bpp + (y + i) * sl) = mlx_get_color_value(mlx_ptr, 0xFF00FF);
	  j = -1;
  }
  mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
  mlx_loop(mlx_ptr);
}
