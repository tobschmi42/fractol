#include <stdlib.h>

//typed struct s_set_data
//{
//	int
//}
const double	g_width = 500;
const double	g_heigth = 500;


typedef struct s_image_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mode;
	t_imaginary	julia;
} t_image_data;

typedef struct	s_imaginary
{
	double	real;
	double	imaginary;
} t_imaginary;

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
	int transparency;
} t_color;

size_t	mandelbrot(t_imaginary z, const double x, const double y, size_t iteration);
void	paint(int color, int x, int y, t_image_data *data);
void	update_image(t_image_data *data, int type, t_color color, t_imaginary i_num);
t_color	extract_color(int color);

