#include <unistd.h>
#include <math.h>
#include <mlx.h>
#include "fractol.h"

void	square_imag(t_imaginary *z)
{
	float	old_real;
	float	old_imaginary;

	old_real = z->real;
	old_imaginary = z->imaginary;
	z->real = ((old_real * old_real) - (old_imaginary * old_imaginary));
	z->imaginary = (2 * old_real * old_imaginary);
}

float	absolute_imaginary(float real,float imag)
{
	return (sqrt(real * real + imag * imag));
}
#include <stdio.h>
size_t	mandelbrot(t_imaginary z, float x, float y, size_t iteration)
{
	printf("Iteration %zu, x: %f, y: %f\n", iteration, z.real, z.imaginary);
	if (iteration >= 100 || absolute_imaginary(z.real, z.imaginary) > 2)
		return (iteration);
	
	square_imag(&z);
	z.real += x;
	z.imaginary += y;
	++iteration;
	return (mandelbrot(z, x, y, iteration));
}
/*
#include <stdio.h>
int main ()
{
	t_imaginary z;
	z.imaginary = 0;
	z.real = 0;
	printf("%zu iterations\n", mandelbrot(z, 0, 0, 0));
	printf("%zu iterations\n", mandelbrot(z, 0, 50, 0));
	
}*/