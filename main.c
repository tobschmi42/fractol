#include <mlx.h>
#include <math.h>
#include "fractol.h"
#include "libft/libft.h"


void	paint(int color, int x, int y, t_image_data *data)
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
double ft_atod_julia(char *str)
{
	long	significand;
	int		exponent;
	size_t	runner;

	exponent = 0;
	runner = 0;
	significand = 0;
	if (ft_isdigit(str[runner]))
		significand = str[runner++] - '0';
	if (str[runner] == '.')
		++runner;
	while (str[runner++] == '0')
	{
		if (exponent < 1 - (pow(2,11) / 2))
			print_commands();
		exponent--;
	}
	while (ft_isdigit(str[runner]))
	{
		significand = (significand * 10) + (str[runner] - '0');
		if (significand > pow(2, 53))
			print_commands();
		++runner;
	}
	printf("Mantisse: %ld, Exponent: %i\n", significand, exponent);
	return (significand * pow(10, exponent));
}

void	print_commands()
{
	ft_putendl_fd("Please call fractol with these parameters:", 1);
	ft_putendl_fd("\tMandelbrot:", 1);
	ft_putendl_fd("\t\t/client 0", 1);
	ft_putendl_fd("\tJulia set:", 1);
	ft_putendl_fd("\t\t/client 1 [real number] [imaginary number]", 1);
	ft_putendl_fd("The numbers for the julia set have to be between -2 and 2", 1);
	exit(0);
}

void	parse_args(char ** input, t_image_data *data)
{
	if (input[1][0] == '0' && !input[2])
		data->mode = 0;
	else if (input[1][0] == '1' && input[2] && input[3] && input[4])
	{
		data->mode = 1;
		data->julia.real = ft_atod_julia(input[2]);
		data->julia.imaginary = ft_atod_julia(input[3]);
	}
	else
		print_commands();
}

//int main(int num, char **args)
//{
//	void 	*mlx;
//	void	*window;
//	t_image_data	img;

//	if (num < 2)
//		print_commands();
//	parse_args(args, &img);
//	mlx = mlx_init();
//	window = mlx_new_window(mlx, g_width, g_heigth, "Enjoy your trip");
//	img.img = mlx_new_image(mlx, g_width, g_heigth);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	t_imaginary i_num ;{i_num.real = -0.6; i_num.imaginary = 0.6;};
//	update_image(&img, 1, extract_color(0x00FF0000), i_num);
//	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
//	mlx_hook(window, 17, 1l << 0, close, 0);
//	mlx_loop(mlx);
//}
