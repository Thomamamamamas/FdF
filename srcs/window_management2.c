#include "../headers/fdf.h"
#include <stdio.h>

void	ajust_window_size(t_fdf *fdf)
{
	int		can_reduce;
	float	tmp1;
	float	tmp2;

	can_reduce = 1;
	while (can_reduce)
	{
		tmp1 = fdf->prog.win_height;
		tmp2 = fdf->prog.win_width;
		if (fdf->low < fdf->prog.win_height - 10 - fdf->high)
			fdf->prog.win_height = fdf->prog.win_height - 10;
		if (fdf->right < fdf->prog.win_width - 10 - fdf->left)
			fdf->prog.win_width = fdf->prog.win_width - 10;
		if (tmp1 == fdf->prog.win_height && tmp2 == fdf->prog.win_width)
			can_reduce = 0;
	}
}
