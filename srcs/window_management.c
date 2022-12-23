#include "../headers/fdf.h"
#include "stdio.h"

void	init_window(t_fdf *fdf)
{
	get_window_size(fdf);
	get_margins(fdf);
	fdf->prog.mlx = mlx_init();
	fdf->prog.win = mlx_new_window(fdf->prog.mlx, fdf->prog.win_width, fdf->prog.win_height, "FdF");
}

void	get_window_size(t_fdf *fdf)
{
	while (fdf->prog.win_width > 1920 || fdf->prog.win_height > 1080)
	{
		get_margins(fdf);
		if (try_adapt_grid_size(fdf) == 0)
		{
			if (fdf->prog.win_width > 1920)
				fdf->prog.win_width = 1920;
			if (fdf->prog.win_height > 1080)
				fdf->prog.win_height = 1080;
		}
		else
		{
			fdf->prog.win_width = fdf->right - fdf->left + fdf->prog.grid * 2;
			fdf->prog.win_height = fdf->bottom - fdf->top + fdf->prog.grid * 2;
		}
	}
}

void	get_margins(t_fdf *fdf)
{
	if (fdf->left < 0 || fdf->right > fdf->prog.win_width)
	{
		if (fdf->left < fdf->prog.grid)
			fdf->prog.marginx = fabs(fdf->left) + fdf->prog.grid * 4;
		else if (fdf->right > fdf->prog.win_width)
			fdf->prog.marginx = fdf->prog.marginx - fdf->prog.grid - (fdf->right - fdf->prog.win_width);
	}
	if (fdf->top < 0 || fdf->bottom > fdf->prog.win_height)
	{
		if (fdf->top < fdf->prog.grid)
			fdf->prog.marginy = fabs(fdf->top) + fdf->prog.grid * 4;
		else if (fdf->bottom > fdf->prog.win_height)
			fdf->prog.marginy = fdf->prog.marginy - fdf->prog.grid - (fdf->bottom - fdf->prog.win_height);
	}
	convert_coords(fdf);
	get_matrix_limits(fdf);
}

int		try_adapt_grid_size(t_fdf *fdf)
{
	if (fdf->prog.grid > 2)
	{
		fdf->prog.grid--;
		convert_coords(fdf);
		get_matrix_limits(fdf);
		return (1);
	}
	return (0);
}

