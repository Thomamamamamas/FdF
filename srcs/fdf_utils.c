/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:19:48 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 16:46:06 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"
#include <stdio.h>

void	end_fdf(t_fdf *fdf)
{
	free_int_2d_array(fdf->cartesian, fdf->matrix_line);
	free_vector2_array(fdf->isometric, fdf->matrix_line);
}

t_vector2	**malloc_2d_t_vector2(int line, int *col)
{
	int			n;
	t_vector2	**res;

	n = 0;
	res = (t_vector2 **)malloc(sizeof(t_vector2 *) * line);
	while (n < line)
	{
		res[n] = (t_vector2 *)malloc(sizeof(t_vector2) * col[n]);
		n++;
	}
	return (res);
}

void	free_int_2d_array(int	**array, int line)
{
	line--;
	while (line > 0)
		free(array[line--]);
	free(array);
}

void	free_vector2_array(t_vector2 **array, size_t line)
{
	line--;
	while (line > 0)
		free(array[line--]);
	free(array);
}

void	set_relief_dimension(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
		printf("higher : %d\n", fdf->prog.relief_higher);
	while (y < fdf->matrix_line)
	{
		x = 0;
		printf("higher : %d\n", fdf->prog.relief_higher);
		printf("high : %d\n", fdf->prog.relief_high);
		printf("medium : %d\n", fdf->prog.relief_medium);
		printf("low : %d\n", fdf->prog.relief_low);
		printf("lower : %d\n", fdf->prog.relief_lower);
		while (x < fdf->matrix_col[y])
		{
			if (fdf->cartesian[y][x] > fdf->prog.relief_higher)
				fdf->prog.relief_higher = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_higher && fdf->cartesian[y][x] > fdf->prog.relief_high)
				fdf->prog.relief_high = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_high && fdf->cartesian[y][x] > fdf->prog.relief_medium_high)
				fdf->prog.relief_medium_high = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_high && fdf->cartesian[y][x] > fdf->prog.relief_medium)
				fdf->prog.relief_medium = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_medium && fdf->cartesian[y][x] > fdf->prog.relief_medium_low)
				fdf->prog.relief_medium_low = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_lower && fdf->cartesian[y][x] > fdf->prog.relief_low)
				fdf->prog.relief_low = fdf->cartesian[y][x];
			else if (fdf->cartesian[y][x] < fdf->prog.relief_lower)
				fdf->prog.relief_lower = fdf->cartesian[y][x];
			x++;
		}
		y++;
	}
}
