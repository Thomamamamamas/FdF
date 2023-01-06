/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:19:48 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/06 12:48:42 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"

t_fdf	init_fdf(char *file)
{
	t_fdf	fdf;
	int		fd;

	fdf.prg.error_code = 0;
	fdf.colorset_id = 0;
	fdf.colorset = assign_colorset(fdf.colorset_id);
	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		fdf.prg.error_code = 1;
		return (fdf);
	}
	allocate_matrix(&fdf, file);
	parse_map(&fdf, fd);
	get_matrix_relief(&fdf);
	fdf.prg.grid = GRID;
	fdf.prg.marginx = 0;
	fdf.prg.marginy = 0;
	fdf.prg.width = 1921;
	fdf.prg.height = 1081;
	convert_coords(&fdf);
	get_matrix_limits(&fdf);
	get_matrix_colors(&fdf);
	close(fd);
	return (fdf);
}

void	error_gestion(t_fdf *fdf)
{
	if (fdf->prg.error_code == 1)
		ft_putstr_fd("Error: Can't open file", 2);
	else if (fdf->prg.error_code == 2)
		ft_putstr_fd("Error: Line in file not valid", 2);
	else if (fdf->prg.error_code == 3)
		ft_putstr_fd("Error: Need one argument", 2);
	else if (fdf->prg.error_code == 4)
		ft_putstr_fd("Error: Too many arguments", 2);
}

void	get_matrix_limits(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->top = fdf->mx[0][0].y;
	fdf->bottom = fdf->mx[0][0].y;
	fdf->left = fdf->mx[0][0].x;
	fdf->right = fdf->mx[0][0].x;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
		{
			if (fdf->mx[y][x].y < fdf->top)
				fdf->top = fdf->mx[y][x].y;
			if (fdf->mx[y][x].y > fdf->bottom)
				fdf->bottom = fdf->mx[y][x].y;
			if (fdf->mx[y][x].x < fdf->left)
				fdf->left = fdf->mx[y][x].x;
			if (fdf->mx[y][x].x > fdf->right)
				fdf->right = fdf->mx[y][x].x;
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
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
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
