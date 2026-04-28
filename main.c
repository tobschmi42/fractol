/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:29:06 by tobschmi          #+#    #+#             */
/*   Updated: 2026/04/28 23:56:59 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft/libft.h"

int	close_img(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (1);
}

void	print_commands(int out)
{
	ft_putendl_fd("Please call fractol with these parameters:", 1);
	ft_putendl_fd("\tMandelbrot:", 1);
	ft_putendl_fd("\t\t/fractol 0", 1);
	ft_putendl_fd("\tJulia set:", 1);
	ft_putendl_fd("\t\t/fractol 1 [real number] [imaginary number]", 1);
	ft_putendl_fd("The numbers for the julia set have to be between\
		 -2 and 2, and must be a valid double", 1);
	exit(out);
}

void	parse_args(char **input, t_data *data)
{
	if (input[1][0] == '0' && !input[2])
		data->mode = 0;
	else if (input[1][0] == '1' && input[2] && input[3] && !input[4])
	{
		data->mode = 1;
		data->julia.real = ft_atod_julia(input[2]);
		data->julia.imaginary = ft_atod_julia(input[3]);
	}
	else
		print_commands(0);
}

void	initialize_variables(void **mlx, void **window, t_data *data)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd("Setting up MLX Failed\n", 1);
		exit(1);
	}
	*window = mlx_new_window(*mlx, G_WIDTH, G_HEIGHT, "Enjoy your trip");
	if (!*window)
	{
		free(*mlx);
		ft_putstr_fd("Setting up window failed\n", 1);
		exit(1);
	}
	data->img = mlx_new_image(*mlx, G_WIDTH, G_HEIGHT);
	if (!data->img)
	{
		mlx_destroy_window(*mlx, *window);
		free(*mlx);
		ft_putstr_fd("Setting up image failed\n", 1);
		exit(1);
	}
}

int	main(int num, char **args)
{
	void	*mlx;
	void	*window;
	t_data	data;

	if (num < 2)
		print_commands(0);
	parse_args(args, &data);
	initialize_variables(&mlx, &window, &data);
	data.image_data.addr = mlx_get_data_addr(
			data.img,
			&data.image_data.bits_per_pixel,
			&data.image_data.line_length,
			&data.image_data.endian);
	data.mlx = mlx;
	data.window = window;
	data.image_data.zoom = 1;
	mlx_mouse_hook(window, mouse_controller, &data);
	mlx_key_hook(window, key_controller, &data);
	mlx_hook(window, 17, 1l << 0, close_img, &data);
	mlx_loop_hook(mlx, update_image, &data);
	mlx_loop(mlx);
}
