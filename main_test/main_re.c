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

int		my_fonct_key(int keycode, void)
{
	ft_putnbr_end(keycode);
	if (keycode == 53)
		ft_error("ESC : Good Bye My Friend");
	return (0);
}

int       main()
{
  void  *mlx_init();
  int   bpp;
  int   sizeline;
  int   endian;
  int   *img;
  char  *data;
  void  *mlx_ptr;
  void  *win_ptr;
  int   pixel_nbr;

  pixel_nbr = 0;
  mlx_ptr = mlx_init();
  img = mlx_new_image(mlx_ptr, 300, 300);
  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  printf("%d, %d, %d\n", bpp, sizeline, endian);
  while (pixel_nbr < 360000)
    {
      data[pixel_nbr] = 50;
      pixel_nbr++;
    }
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fenetre de Astaroth");
  mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100, 100);
	mlx_key_hook(win_ptr, my_fonct_key, void);
  mlx_loop(mlx_ptr);
}
