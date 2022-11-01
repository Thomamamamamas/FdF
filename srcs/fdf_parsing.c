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
void	parse_map(t_fdf *fdf, char *file)
{
	char	*str;
	int	fd;
	int	i;

	i = 0;
	fdf->prog.error_code = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
		fdf->prog.error_code = 1;
	fdf->matrix_line = number_of_line(file);
	fdf->cartesian = (int **)malloc(sizeof(int *) * fdf->matrix_line + 1);
	fdf->matrix_col = (int *)malloc(sizeof(int) * fdf->matrix_line + 1);
	while (1)
	{
		str = get_next_line(fd);
		if (!str || fdf->prog.error_code != 0)
		{
			if (str)
				free(str);
			close(fd);
			fdf->matrix_line = i;
			return ;
		}
		else
			parse_actual_line(fdf, str, i);
		i++;
	}
}

//renvoie la taille d'un array 2 dimension
size_t	len_2d_char_array(char **array)
{
	int	n;

	n = 0;
	while (array[n] != NULL)
		n++;
	return (n);
}

void	parse_actual_line(t_fdf *fdf, char *str, int i)
{
	char	**line;
	int		j;
	int		n;

	line = ft_split(str, ' ');
	j = 0;
	while (line[j] != NULL)
	{
		n = 0;
		while (line[j][n])
		{
			if (!ft_isdigit(line[j][n]) && line[j][n] != '\n' && line[j][n] != ' ')
				fdf->prog.error_code = 2;
			n++;
		}
		j++;
	}
	fdf->cartesian[i] = (int *)malloc(sizeof(int) * j + 1);
	fdf->matrix_col[i] = j;
	j = 0;
	while (line[j] != NULL && fdf->prog.error_code == 0)
	{
		fdf->cartesian[i][j] = ft_atoi(line[j]);
		j++;
	}
}
