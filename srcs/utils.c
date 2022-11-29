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

	fdf.high = 1080;
	fdf.low = 0;
	fdf.left = 1920;
	fdf.right = 0;
	fdf.prog.error_code = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
		fdf.prog.error_code = 1;
	allocate_matrix(&fdf, file);
	parse_map(&fdf, fd);
	close(fd);
	return (fdf);
}

void	end_fdf(t_fdf *fdf)
{
	free_vector2_array(fdf->matrix, fdf->matrix_line);
}

void	free_vector2_array(t_vector2 **array, size_t line)
{
	line--;
	while (line > 0)
		free(array[line--]);
	free(array);
}

void	get_matrix_limits(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			if (fdf->matrix[y][x].y < fdf->high)
				fdf->high = fdf->matrix[y][x].y;
			if (fdf->matrix[y][x].y > fdf->low)
				fdf->low = fdf->matrix[y][x].y;
			if (fdf->matrix[y][x].x < fdf->left)
				fdf->left = fdf->matrix[y][x].x;
			if (fdf->matrix[y][x].x > fdf->right)
				fdf->right = fdf->matrix[y][x].x;
			x++;
		}
		y++;
	}
}
