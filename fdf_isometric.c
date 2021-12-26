/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:15:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 17:00:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_vector3	**get_cartesian_coord(char **map, t_parse *parser)
{
	t_vector3	vector3_tmp;
	t_vector3	**coord_carts;
	float		*nb_array;
	size_t		y;
	size_t		x;

	y = 0;
	coord_carts = (t_vector3 **)malloc(sizeof(t_vector3 *) * parser->y + 1);
	while (y < parser->y)
	{
		x = 0;
		nb_array = get_nbr(map[y]);
		coord_carts[y] = (t_vector3 *)malloc(sizeof(t_vector3) * parser->x[y] + 1);
		while (x < parser->x[y])
		{
			vector3_tmp.x = x * GRID_SIZEX;
			vector3_tmp.y = y * GRID_SIZEY;
			vector3_tmp.z = nb_array[x];
			coord_carts[y][x] = vector3_tmp;
			x++;
		}
		y++;
	}
	return (coord_carts);
}

t_vector2	**cartesian_to_iso(t_vector3 **coords, t_parse *parser)
{
	size_t		x;
	size_t		y;
	t_vector2	**coords_iso;

	y = 0;
	coords_iso = (t_vector2 **)malloc(sizeof(t_vector2 *) * parser->y + 1);
	while (y < parser->y)
	{
		coords_iso[y] = (t_vector2 *)malloc(sizeof(t_vector2) * parser->x[y] + 1);
		x = 0;
		while (x < parser->x[y])
		{
			coords_iso[y][x].x = (coords[y][x].x * cos(RAD30) + coords[y][x].y * cos(RAD30 + RAD120) + coords[y][x].z * cos(RAD30 - RAD120));
			coords_iso[y][x].y = (coords[y][x].x * sin(RAD30) + coords[y][x].y * sin(RAD30 + RAD120) + coords[y][x].z * sin(RAD30 - RAD120));
			x++;
		}
		y++;
	}
	return (coords_iso);
}

int		**get_relief_color(t_program *prog, t_vector3 **coord_carts, t_parse *parser)
{
	int	**relief_colors;

	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	relief_colors = (int **)malloc(sizeof(int *) * parser->y + 1);
	printf("higher = %d\n", prog->relief_higher);
	printf("high = %d\n", prog->relief_high);
	printf("medium = %d\n", prog->relief_medium);
	printf("low = %d\n", prog->relief_low);
	printf("lower = %d\n", prog->relief_lower);
	while (y < parser->y)
	{
		x = 0;
		relief_colors[y] = (int *)malloc(sizeof(int) * parser->x[y] + 1);
		while (x < parser->x[y])
		{
			if (coord_carts[y][x].z >= prog->relief_higher)
				relief_colors[y][x] = COLOR_MAX6;
			else if (coord_carts[y][x].z >= prog->relief_high)
				relief_colors[y][x] = COLOR_MAX4;
			else if (coord_carts[y][x].z >= prog->relief_medium_high)
				relief_colors[y][x] = COLOR_MAX2;
			else if (coord_carts[y][x].z >= prog->relief_medium)
				relief_colors[y][x] = COLOR_0;
			else if (coord_carts[y][x].z >= prog->relief_medium_low)
				relief_colors[y][x] = COLOR_MIN2;
			else if (coord_carts[y][x].z >= prog->relief_low)
				relief_colors[y][x] = COLOR_MIN4;
			else if (coord_carts[y][x].z >= prog->relief_lower)
				relief_colors[y][x] = COLOR_MIN6;
			else
				relief_colors[y][x] = 0x00FFFFFF;
			x++;
		}
		y++;
	}
	return (relief_colors);
}
