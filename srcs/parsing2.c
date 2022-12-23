#include "../headers/fdf.h"
#include <stdio.h>

void	parse_actual_line(t_fdf *fdf, char *str, int y)
{
	char	**line;
	int		x;

	line = ft_split(str, ' ');
	x = 0;
	while (line[x] != NULL && fdf->prog.error_code == 0)
	{
		parse_actual_coord(fdf, line[x], x, y);
		x++;
	}
}

void	parse_actual_coord(t_fdf *fdf, char *str, int x, int y)
{
	fdf->coords[y][x].x = x;
	fdf->coords[y][x].y = y;
	fdf->coords[y][x].z = ft_atoi(str);
}

void	actual_coord_to_iso(t_fdf *fdf, int x, int y, int z)
{
	fdf->matrix[y][x].x = x * cos(0.5235) + y * cos(0.5335 + 2.0944) + z * cos(0.5235 - 2.0944);
	fdf->matrix[y][x].y = x * sin(0.5235) + y * sin(0.5235 + 2.0944) + z * sin(0.5235 - 2.0944);
	fdf->matrix[y][x].x = (fdf->matrix[y][x].x * fdf->prog.grid) + fdf->prog.marginx;
	fdf->matrix[y][x].y = (fdf->matrix[y][x].y * fdf->prog.grid) + fdf->prog.marginy;
}


void	convert_coords(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			actual_coord_to_iso(fdf, x, y, fdf->coords[y][x].z);
			x++;
		}
		y++;
	}
	get_matrix_limits(fdf);
}

int	is_hexadecimal_nb(char *str)
{
	int	n;
	int	comma;
	int	x;

	n = 0;
	comma = 0;
	x = 0;
	if (ft_strnstr(str, "0x", ft_strlen(str)) && ft_strlen(str) >= 8)
	{
		if (str[n] == ',' && comma == 0)
			comma = 1;
		else if (str[n] == 'x' && x == 0)
			x = 1;
		else if (!ft_isdigit(str[n]) && str[n] != '\n')
			return (0);
		n++;
	}
	else
		return (0);
	return (1);
}
