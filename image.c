/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:24:07 by tobschmi          #+#    #+#             */
/*   Updated: 2026/04/28 23:35:55 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	paint(int color, int x, int y, t_image_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	update_mandelbrot(t_image_data *data)
{
	t_imaginary	x_y;
	int			hue;
	t_imaginary	pixel;
	t_imaginary	start;

	start.real = 0;
	start.imaginary = 0;
	x_y.imaginary = -2;
	pixel.imaginary = 0;
	while (x_y.imaginary < 2)
	{
		x_y.real = -2;
		pixel.real = 0;
		while (x_y.real < 2)
		{
			hue = 0x0000FFFF * fractal(start, x_y.real / data->zoom,
					x_y.imaginary / data->zoom, 0);
			paint(hue, pixel.real, pixel.imaginary, data);
			x_y.real += 4.0 / G_WIDTH;
			++pixel.real;
		}
		x_y.imaginary += 4.0 / G_HEIGHT;
		++pixel.imaginary;
	}
}

static void	update_julia(t_image_data *data, const t_imaginary set)
{
	t_imaginary	x_y;
	int			hue;
	t_imaginary	pixel;
	t_imaginary	temp;

	x_y.imaginary = -2;
	pixel.imaginary = 0;
	while (x_y.imaginary < 2)
	{
		x_y.real = -2;
		pixel.real = 0;
		while (x_y.real < 2)
		{
			temp.real = x_y.real / data->zoom;
			temp.imaginary = x_y.imaginary / data->zoom;
			hue = 0x0012346A * fractal(temp, set.real, set.imaginary, 0);
			paint(hue, pixel.real, pixel.imaginary, data);
			x_y.real += (4.0 / G_WIDTH);
			++pixel.real;
		}
		x_y.imaginary += 4.0 / G_HEIGHT;
		++pixel.imaginary;
	}
}

int	update_image(t_data *data)
{
	if (data->mode == 0)
		update_mandelbrot(&data->image_data);
	else
		update_julia(&data->image_data, data->julia);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}
