#include "fractol.h"

t_color extract_color(int color)
{
	t_color extracted;

	extracted.transparency = (color >> 24) & 0xFF;
	extracted.red = (color >> 16) & 0xFF;
	extracted.green = (color >> 8) & 0xFF;
	extracted.blue = (color >> 0) & 0xFF;
	return (extracted);
}

int get_color(t_color start, t_color end, float percentage)
{
	int color;

	color = 0;
	color |= ((int)(start.transparency +
					(end.transparency - start.transparency) * percentage)
			  << 24);
	color |= ((int)(start.red + (end.red - start.red) * percentage) << 16);
	color |= ((int)(start.green +
					(end.green - start.green) * percentage)
			  << 8);
	color |= ((int)(start.blue + (end.blue - start.blue) * percentage));
	return (color);
}

void update_mandelbrot(t_image_data *data, t_color color)
{
	t_imaginary x_y;
	int hue;
	t_imaginary pixel;

	x_y.imaginary = -2;
	pixel.imaginary = 0;
	while (x_y.imaginary < 2)
	{
		x_y.real = -2;
		pixel.real = 0;
		while (x_y.real < 2)
		{
			hue = get_color(color, extract_color(0x0000FF00),
							mandelbrot(x_y, x_y.real, x_y.imaginary, 0));
			paint(hue, pixel.real, pixel.imaginary, data);
			x_y.real += 4.0 / g_width;
			++pixel.real;
		}
		x_y.imaginary += 4.0 / g_heigth;
		++pixel.imaginary;
	}
}

void update_julia(t_image_data *data, t_color color, const t_imaginary set)
{
	t_imaginary x_y;
	int hue;
	t_imaginary pixel;

	x_y.imaginary = -2;
	pixel.imaginary = 0;
	while (x_y.imaginary < 2)
	{
		x_y.real = -2;
		pixel.real = 0;
		while (x_y.real < 2)
		{
			hue = get_color(color, extract_color(0x0000FF00),
							mandelbrot(x_y, set.real, set.imaginary, 0));
			paint(hue, pixel.real, pixel.imaginary, data);
			x_y.real += 4.0 / g_width;
			++pixel.real;
		}
		x_y.imaginary += 4.0 / g_heigth;
		++pixel.imaginary;
	}
}

void update_image(t_image_data *data, int type, t_color color, t_imaginary i_num)
{
	if (!type)
		update_mandelbrot(data, color);
	else if (type == 1)
		update_julia(data, color, i_num);
}