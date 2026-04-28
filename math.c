/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:07:29 by tobschmi          #+#    #+#             */
/*   Updated: 2026/04/28 23:15:45 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fractol.h"

static void	square_imag(t_imaginary *z)
{
	float	old_real;
	float	old_imaginary;

	old_real = z->real;
	old_imaginary = z->imaginary;
	z->real = ((old_real * old_real) - (old_imaginary * old_imaginary));
	z->imaginary = (2 * old_real * old_imaginary);
}

int	fractal(t_imaginary z, const double x, const double y, int iteration)
{
	if (iteration >= MAX_ITER
		|| (z.real * z.real) + (z.imaginary * z.imaginary) > 4.0)
	{
		if (iteration >= MAX_ITER)
			return (0);
		else if (iteration == 0)
			return (MAX_ITER);
		else
			return (iteration);
	}
	square_imag(&z);
	z.real += x;
	z.imaginary += y;
	++iteration;
	return (fractal(z, x, y, iteration));
}
/*
int main ()
{
	t_imaginary z;
	z.imaginary = 0;
	z.real = 0;
	printf("%zu iterations\n", fractal(z, 0, 0, 0));
	printf("%zu iterations\n", fractal(z, 0, 50, 0));
}*/
