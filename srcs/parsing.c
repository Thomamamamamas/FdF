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

//Compte le nombre de ligne du fichier
int	number_of_line(char *file)
{
	int		fd;
	int		line;
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
	int		y;

	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str || fdf->prg.error_code != 0)
		{
			if (str)
				free(str);
			fdf->mx_line = y;
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
	fdf->mx_line = number_of_line(file);
	fdf->coords = (t_v3 **)malloc(sizeof(t_v3 *) * fdf->mx_line + 1);
	fdf->mx = (t_v2 **)malloc(sizeof(t_v2 *) * fdf->mx_line + 1);
	fdf->mx_col = (int *)malloc(sizeof(int) * fdf->mx_line + 1);
}

void	allocate_actual_line(t_fdf *fdf, char *str, int y)
{
	char	**tmp;
	int		x;
	int		n;

	tmp = ft_split(str, ' ');
	x = 0;
	while (tmp[x] != NULL)
	{
		n = 0;
		while (tmp[x][n] && !is_hexadecimal_nb(tmp[x]))
		{
			if (tmp[x][n] == '-')
				n++;
			if (!ft_isdigit(tmp[x][n]) && tmp[x][n] != '\n' && tmp[x][n] != ' ')
				fdf->prg.error_code = 2;
			n++;
		}
		x++;
	}
	free_2d_char(tmp);
	fdf->coords[y] = (t_v3 *)malloc(sizeof(t_v3) * x + 1);
	fdf->mx[y] = (t_v2 *)malloc(sizeof(t_v2) * x + 1);
	fdf->mx_col[y] = x;
}

void	parse_windows_info(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->prg.max_height = fdf->mx_line;
	fdf->prg.max_width = fdf->mx_col[y];
	while (y < fdf->mx_line)
	{
		x = 0;
		if (fdf->mx_col[y] > fdf->prg.max_width)
			fdf->prg.max_width = fdf->mx_col[y];
		while (x < fdf->mx_col[y])
			x++;
		y++;
	}
}
