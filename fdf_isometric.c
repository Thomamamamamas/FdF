/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:15:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/22 15:51:04 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_vector3	**get_cartesian_coord(char **height_array, t_parse *parser)
{
	t_vector3	vector3_tmp;
	t_vector3	**cart_coord_array;
	float		*nb_array;
	size_t		y;
	size_t		x;

	y = 0;
	cart_coord_array = (t_vector3 **)malloc(sizeof(t_vector3 *) * parser->y + 1);
	printf("cartesien :\n");
	while (y < parser->y)
	{
		x = 0;
		nb_array = get_nbr(height_array[y]);
		cart_coord_array[y] = (t_vector3 *)malloc(sizeof(t_vector3) * parser->x[y] + 1);
		while (x < parser->x[y])
		{
			vector3_tmp.x = x * GRID_SIZEX;
			vector3_tmp.y = y * GRID_SIZEY;
			vector3_tmp.z = nb_array[x];
			cart_coord_array[y][x] = vector3_tmp;
			x++;
		}
		y++;
	}
	print_vector3_array(cart_coord_array, parser->y, parser->x);
	return (cart_coord_array);
}

t_vector2	**cartesian_to_iso(t_vector3 **coord, t_parse *parser)
{
	size_t		x;
	size_t		y;
	t_vector2	**coord_iso;

	y = 0;
	coord_iso = (t_vector2 **)malloc(sizeof(t_vector2 *) * parser->y + 1);
	printf("isometrique :\n");
	while (y < parser->y)
	{
		coord_iso[y] = (t_vector2 *)malloc(sizeof(t_vector2) * parser->x[y] + 1);
		x = 0;
		while (x < parser->x[y])
		{
			coord_iso[y][x].x = (coord[y][x].x * cos(0.523599) + coord[y][x].y * cos(0.523599 + 2.0944) + coord[y][x].z * cos(0.523599 - 2.0944));
			coord_iso[y][x].y = (coord[y][x].x * sin(0.523599) + coord[y][x].y * sin(0.523599 + 2.0944) + coord[y][x].z * sin(0.523599 - 2.0944));
			x++;
		}
		y++;
	}
	print_vector2_array(coord_iso, parser->y, parser->x);
	free_vector3_array(coord, parser->y);
	return (coord_iso);
}
