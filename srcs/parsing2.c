#include "../headers/fdf.h"

void	parse_actual_line(t_fdf *fdf, char *str, int y)
{
	char	**line;
	int		x;

	line = ft_split(str, ' ');
	x = 0;
	while (line[x] != NULL && fdf->prg.error_code == 0)
	{
		parse_actual_coord(fdf, line[x], x, y);
		x++;
	}
	free_2d_char(line);
}

void	parse_actual_coord(t_fdf *fdf, char *str, int x, int y)
{
	fdf->coords[y][x].x = x;
	fdf->coords[y][x].y = y;
	fdf->coords[y][x].z = ft_atoi(str);
}

void	actual_coord_to_iso(t_fdf *fdf, int x, int y, int z)
{
	fdf->mx[y][x].x = x * cos(0.52) + y * cos(0.53 + 2.09);
	fdf->mx[y][x].x = fdf->mx[y][x].x + z * cos(0.52 - 2.09);
	fdf->mx[y][x].x = (fdf->mx[y][x].x * fdf->prg.grid) + fdf->prg.marginx;
	fdf->mx[y][x].y = x * sin(0.52) + y * sin(0.52 + 2.09);
	fdf->mx[y][x].y = fdf->mx[y][x].y + z * sin(0.52 - 2.09);
	fdf->mx[y][x].y = (fdf->mx[y][x].y * fdf->prg.grid) + fdf->prg.marginy;
}

void	convert_coords(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
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
