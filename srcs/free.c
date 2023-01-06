/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:02:55 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/06 12:48:40 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"
#include <stdio.h>

int	end_fdf(t_fdf *fdf)
{
	if (fdf->prg.error_code != 1)
	{
		free_vector2_array(fdf->mx, fdf->mx_line);
		free_vector3_array(fdf->coords, fdf->mx_line);
		free(fdf->mx_col);
		if (fdf->prg.error_code != 2)
			mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	exit(0);
	return (0);
}

void	free_2d_char(char **str)
{
	int	n;

	n = 0;
	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
}

void	free_vector2_array(t_v2 **array, int line)
{
	int	y;

	y = 0;
	while (y < line)
	{
		free(array[y]);
		y++;
	}
	free(array);
}

void	free_vector3_array(t_v3 **array, int line)
{
	int	y;

	y = 0;
	while (y < line)
	{
		free(array[y]);
		y++;
	}
	free(array);
}
