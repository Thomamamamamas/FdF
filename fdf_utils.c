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

#include "fdf.h"
#include <stdio.h>

void	free_vector3_array(t_vector3 **array, size_t line)
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

void	set_relief_dimension(t_program *prog, t_vector3 **coords, t_parse *parser)
{
	size_t	x;
	size_t	y;

	y = 0;
		printf("higher : %d\n", prog->relief_higher);
	while (y < parser->y)
	{
		x = 0;
		printf("higher : %d\n", prog->relief_higher);
		printf("high : %d\n", prog->relief_high);
		printf("medium : %d\n", prog->relief_medium);
		printf("low : %d\n", prog->relief_low);
		printf("lower : %d\n", prog->relief_lower);
		while (x < parser->x[y])
		{
			if (coords[y][x].z > prog->relief_higher)
				prog->relief_higher = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_higher && coords[y][x].z > prog->relief_high)
				prog->relief_high = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_high && coords[y][x].z > prog->relief_medium_high)
				prog->relief_medium_high = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_high && coords[y][x].z > prog->relief_medium)
				prog->relief_medium = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_medium && coords[y][x].z > prog->relief_medium_low)
				prog->relief_medium_low = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_lower && coords[y][x].z > prog->relief_low)
				prog->relief_low = coords[y][x].z;
			else if (coords[y][x].z < prog->relief_lower)
				prog->relief_lower = coords[y][x].z;
			x++;
		}
		y++;
	}
}
