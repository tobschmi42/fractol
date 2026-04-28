#include <mlx.h>

//typedef struct	s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_image_data;

//void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_image_data	img;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);
//	for(int i = 0; i< 500; i++)
//	{
//		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
//	}
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}

#include "fractol.h"
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include <stdio.h>
//double ft_atod_julia(char *str)
//{
//	long	significand;
//	int		exponent;
//	size_t	runner;

//	exponent = 0;
//	runner = 0;
//	if (str[0] == '0' || str[exponent] == '.')
//		++exponent;
//	if (str[exponent] == '.')
//		++exponent;
//	while (str[exponent] == '0')
//	{
//		if (-exponent++ < 1 - (pow(2,11) / 2))
//			print_commands();
//	}
//	significand = str[exponent] - '0';
//	if (str[exponent] == '.')
//		++runner;
//	while (ft_isdigit(str[exponent + runner]))
//	{
//		significand = (significand * 10) + (str[exponent + runner++] - '0');
//		if (significand > pow(2, 53))
//			print_commands();
//	}
//	return (significand * pow(10, -exponent));
//}

//int main(int num, char **args){
//	(void)num;
//	printf("Double %s: %e\n", args[1], check_double(args[1]));
//}