#include "../headers/fdf.h"
#include <stdio.h>

int	bresenham_increment_v1(int coord1, int coord2)
{
	if (coord1 < coord2)
		return (coord1 + 1);
	return (coord1 - 1);
}

t_rgb	point_color(t_fdf *fdf, float z)
{
	if (z <= fdf->smallest)
		return (hex_rgb(fdf->colorset.color1));
	else if (z < fdf->medium)
		return (hex_rgb(fdf->colorset.color2));
	else if (z >= fdf->medium && z < fdf->largest)
		return (hex_rgb(fdf->colorset.color3));
	else if (z >= fdf->largest)
		return (hex_rgb(fdf->colorset.color4));
	return (hex_rgb(WHITE));
}

int	line_color(t_rgb c1, t_rgb c2, float value)
{
	t_rgb	rgb;

	if (c1.r == c2.r && c1.b == c2.b && c1.g == c2.g)
		return (rgb_hex(c1));
	rgb.r = c1.r * (1 - value) + c2.r * value;
	rgb.g = c1.g * (1 - value) + c2.g * value;
	rgb.g = c1.b * (1 - value) + c2.b * value;
	return (rgb_hex(rgb));
}
