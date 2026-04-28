/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:10:03 by tobschmi          #+#    #+#             */
/*   Updated: 2026/04/28 23:36:25 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define G_WIDTH 400.0
# define G_HEIGHT 400.0
# define MAX_ITER 1000
# define ESC 0xff1b
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# include <stdlib.h>

typedef struct s_imaginary
{
	double	real;
	double	imaginary;
}	t_imaginary;

typedef struct s_image_data
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
}	t_image_data;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	void			*img;
	t_image_data	image_data;
	int				mode;
	t_imaginary		julia;
}	t_data;

int		fractal(t_imaginary z, const double x, const double y, int fractal);
int		update_image(t_data *data);
void	print_commands(int out);
int		close_img(t_data *data);
double	check_back(char *str, long significand, int exponent, size_t runner);
double	ft_atod_julia(char *str);
int		mouse_controller(int keypress, int x, int y, t_data *data);
int		key_controller(int keycode, t_data *data);

#endif