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

t_fdf	init_fdf(char *file)
{
	t_fdf	fdf;
	int		fd;

	fdf.prog.error_code = 0;
	fdf.colorset_id = 0;
	fdf.colorset.color_white = WHITE;
	fdf.colorset = assign_colorset(fdf.colorset_id);
	fd = open(file, O_RDWR);
	if (fd < 0)
		fdf.prog.error_code = 1;
	allocate_matrix(&fdf, file);
	parse_map(&fdf, fd);
	get_matrix_relief(&fdf);
	fdf.prog.grid = GRID;
	fdf.prog.marginx = 0;
	fdf.prog.marginy = 0;
	fdf.prog.win_width = 1921;
	fdf.prog.win_height = 1081;
	convert_coords(&fdf);
	get_matrix_limits(&fdf);
	get_matrix_colors(&fdf);
	close(fd);
	return (fdf);
}

void	get_matrix_limits(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->top = fdf->matrix[0][0].y;
	fdf->bottom = fdf->matrix[0][0].y;
	fdf->left = fdf->matrix[0][0].x;
	fdf->right = fdf->matrix[0][0].x;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			if (fdf->matrix[y][x].y < fdf->top)
				fdf->top = fdf->matrix[y][x].y;
			if (fdf->matrix[y][x].y > fdf->bottom)
				fdf->bottom = fdf->matrix[y][x].y;
			if (fdf->matrix[y][x].x < fdf->left)
				fdf->left = fdf->matrix[y][x].x;
			if (fdf->matrix[y][x].x > fdf->right)
				fdf->right = fdf->matrix[y][x].x;
			x++;
		}
		y++;
	}
}

void	get_matrix_relief(t_fdf *fdf)
{
	int	x;
	int	y;

	fdf->smallest = fdf->coords[0][0].z;
	fdf->medium = 0;
	fdf->largest = fdf->coords[0][0].z;
	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			if (fdf->coords[y][x].z > fdf->largest)
				fdf->largest = fdf->coords[y][x].z;
			if (fdf->coords[y][x].z < fdf->smallest)
				fdf->smallest = fdf->coords[y][x].z;
			fdf->medium = fdf->medium + fdf->coords[y][x].z;
			x++;
		}
		fdf->medium = fdf->medium / x;
		y++;
	}
}
