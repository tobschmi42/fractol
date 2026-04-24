#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct	s_imaginary
{
	float	real;
	float	imaginary;
} t_imaginary;

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
	int transparency;
} t_color;

size_t	mandelbrot(t_imaginary z, float x, float y, size_t iteration);
void	paint(int color, int x, int y, t_data *data);
void	update_image(t_data *data, int type, t_color color, t_imaginary i_num);
t_color	extract_color(int color);

