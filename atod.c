#include <math.h>
#include "libft/libft.h"
#include "fractol.h"

double ft_atod_julia(char *str, long significand, int exponent, size_t runner)
{
	size_t	temp;

	if (str[runner] != '.')
		return (significand);
	++runner;
	while (ft_isdigit(str[runner]))
	{
		temp = 0;
		while (str[runner + temp] == '0')
			++temp;
		if ((str[runner + temp] == '\0') &&
			(significand * pow(10, exponent) > 2))
			print_commands();
		else if (str[runner + temp] == '\0')
			return (significand * pow(10, exponent));
		significand = (significand * 10) + (str[runner] - '0');
		exponent--;
		if ((significand > (long)pow(2, 53)) || (exponent < 1 - (pow(2,11) / 2)))
			print_commands();
		++runner;
	}
	if (significand * pow(10, exponent) > 2)
		print_commands();
	return (significand * pow(10, exponent));
}

double	check_double(char *str)
{
	long	significand;
	size_t	runner;
	int		neg;

	neg = 1;
	runner = 0;
	significand = 0;
	if (str[0] == '-')
	{
		neg = -1;
		++runner;
	}
	if (!ft_isdigit(str[runner]))
		print_commands();
	while (ft_isdigit(str[runner]))
	{
		significand = (significand * 10) + (str[runner] - '0');
		if (significand > 2)
			print_commands();
		++runner;
	}
	return (neg * ft_atod_julia(str, significand, 0, runner));
}	
