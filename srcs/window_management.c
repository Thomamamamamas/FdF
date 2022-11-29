#include "../headers/fdf.h"
#include "stdio.h"

void	init_window(t_fdf *fdf)
{
	get_all_windows_value(fdf);
	while (check_if_window_is_valid(fdf) != 1) ;
	ajust_window_size(fdf);
	fdf->prog.mlx = mlx_init();
	fdf->prog.win = mlx_new_window(fdf->prog.mlx, fdf->prog.win_width, fdf->prog.win_height, "FdF");
}

void	get_all_windows_value(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->prog.max_width;
	fdf->prog.max_width = 2 + tmp * sin(0.5235) + fdf->prog.max_height * sin(0.5235 + 2.0944) + 0 * sin(0.5235 - 2.0944);
	fdf->prog.max_height = 2 + tmp * cos(0.5235) + fdf->prog.max_height * cos(0.5335 + 2.0944) + 0 * cos(0.5235 - 2.0944);
	if (fdf->prog.max_width > fdf->prog.max_height)
		fdf->prog.max_size = fdf->prog.max_width;
	else
		fdf->prog.max_size = fdf->prog.max_height;
	fdf->prog.gridx = GRIDX;
	fdf->prog.gridy = GRIDY;
	update_window_value(fdf);
}

void	update_window_value(t_fdf *fdf)
{
	fdf->prog.marginx = fdf->prog.gridx * fdf->prog.max_width;
	fdf->prog.marginy = fdf->prog.gridy * fdf->prog.max_height;
	fdf->prog.win_height = (fdf->prog.gridy * fdf->prog.max_size) * 2;
	if (fdf->prog.win_height > 1080)
		fdf->prog.win_height = 1080;
	fdf->prog.win_width = (fdf->prog.gridx * fdf->prog.max_size) * 2;
	if (fdf->prog.win_width > 1920)
		fdf->prog.win_width = 1920;
	convert_coords(fdf);
}

int		check_if_window_is_valid(t_fdf *fdf)
{
	if (!check_visible_point(fdf, 0))
	{
		if (fdf->prog.gridx > 10)
		{
			fdf->prog.gridx--;
			fdf->prog.gridy--;
			update_window_value(fdf);
		}
		else
			return (1);
		return (0);
	}
	return (1);
}

int		check_visible_point(t_fdf *fdf, int n)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			if (fdf->matrix[y][x].x + n > fdf->prog.win_height || fdf->matrix[y][x].x + n > fdf->prog.win_width)
				return (0);
			if (fdf->matrix[y][x].y + n > fdf->prog.win_height || fdf->matrix[y][x].y + n > fdf->prog.win_width)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
