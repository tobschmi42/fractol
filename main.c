#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>

#include <stdio.h>
void	paint(int color, int x, int y, t_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close()
{
	exit(0);
	return (1);
}

#include <stdio.h>
int main()
{
	void 	*mlx;
	void	*window;
	t_data	img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 250, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("Go to loop\n");
	printf("Line length: %i, Bits per line: %i", img.line_length, img.bits_per_pixel);
	t_imaginary i_num ;{i_num.real = 0; i_num.imaginary = 0;};
	update_image(&img, 0, extract_color(0x00FF0000), i_num);
	printf("Exited loop\n");
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_hook(window, 17, 1l << 0, close, 0);
	mlx_loop(mlx);
}