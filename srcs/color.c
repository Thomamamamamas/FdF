#include "../headers/fdf.h"

void	get_matrix_colors(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
		{
			fdf->coords[y][x].color = point_color(fdf, fdf->coords[y][x].z);
			fdf->mx[y][x].color = fdf->coords[y][x].color;
			x++;
		}
		y++;
	}
}

t_colorset	assign_colorset(int id)
{
	t_colorset	colorset;

	if (id == 0)
	{
		colorset.color1 = WHITE;
		colorset.color2 = WHITE;
		colorset.color3 = WHITE;
		colorset.color4 = WHITE;
	}
	else if (id == 1)
	{
		colorset.color1 = BLUE_MARINE;
		colorset.color2 = YELLOW;
		colorset.color3 = RED;
		colorset.color4 = PURPLE;
	}
	else
	{
		colorset.color1 = BLUE_CLEAR;
		colorset.color2 = BEIGE;
		colorset.color3 = GREEN;
		colorset.color4 = WHITE;
	}
	return (colorset);
}

t_rgb	hex_rgb(int value)
{
	t_rgb	rgb;

	rgb.r = ((value >> 16) & 0xFF);
	rgb.g = ((value >> 8) & 0xFF);
	rgb.b = ((value) & 0xFF);
	return (rgb);
}

int	rgb_hex(t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16) + ((rgb.g & 0xFF) << 8) + ((rgb.b & 0xFF)));
}
