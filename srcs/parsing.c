/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:54:45 by tcasale           #+#    #+#             */
/*   Updated: 2022/07/03 00:18:47 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"
#include <stdio.h>

//Compte le nombre de ligne du fichier
int	number_of_line(char *file)
{
	int		fd;
	size_t	line;
	char	caracter;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (0);
	line = 0;
	while (read(fd, &caracter, 1) > 0)
	{
		if (caracter == '\n')
			line++;
	}
	close(fd);
	return (line);
}

//Recupere la map est la stock dans un array 2D
void	parse_map(t_fdf *fdf, int fd)
{
	char	*str;
	int	y;

	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str || fdf->prog.error_code != 0)
		{
			if (str)
				free(str);
			fdf->matrix_line = y;
			parse_windows_info(fdf);
			return ;
		}
		else
		{
			allocate_actual_line(fdf, str, y);
			parse_actual_line(fdf, str, y);
		}
		y++;
	}
}

void	allocate_matrix(t_fdf *fdf, char *file)
{
	fdf->matrix_line = number_of_line(file);
	fdf->coords = (t_vector3 **)malloc(sizeof(t_vector3 *) * fdf->matrix_line + 1);
	fdf->matrix = (t_vector2 **)malloc(sizeof(t_vector2 *) * fdf->matrix_line + 1);
	fdf->matrix_col = (int *)malloc(sizeof(int) * fdf->matrix_line + 1);
}

void	allocate_actual_line(t_fdf *fdf, char *str, int y)
{
	char	**line;
	int		x;
	int		n;

	line = ft_split(str, ' ');
	x = 0;
	while (line[x] != NULL)
	{
		n = 0;
		while (line[x][n])
		{
			if (line[x][n] == '-')
				n++;
			if (!ft_isdigit(line[x][n]) && line[x][n] != '\n' && line[x][n] != ' ')
			{
				fdf->prog.error_code = 2;
			}
			
			n++;
		}
		x++;
	}
	fdf->coords[y] = (t_vector3 *)malloc(sizeof(t_vector3) * x + 1);
	fdf->matrix[y] = (t_vector2 *)malloc(sizeof(t_vector2) * x + 1);
	fdf->matrix_col[y] = x;
}

void	parse_windows_info(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->prog.max_height = fdf->matrix_line;
	fdf->prog.max_width = fdf->matrix_col[y];
	while (y < fdf->matrix_line)
	{
		x = 0;
		if (fdf->matrix_col[y] > fdf->prog.max_width)
			fdf->prog.max_width = fdf->matrix_col[y];
		while (x < fdf->matrix_col[y])
			x++;
		y++;
	}
}
