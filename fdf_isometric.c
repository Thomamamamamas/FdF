/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:15:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/13 17:34:42 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_vector3	**get_cartesian_coord(char **height_array, t_parse *parser)
{
	t_vector3	vector3_tmp;
	t_vector3	**cart_coord_array;
	float		*nb_array;
	int			y;
	int			x;
	size_t		len;

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
			vector3_tmp.x = x;
			vector3_tmp.y = y;
			vector3_tmp.z = nb_array[x];
			cart_coord_array[y][x] = vector3_tmp;
			x++;
		}
		y++;
	}
	print_2D_array(cart_coord_array, parser->y, parser->x);
	return (cart_coord_array);
}

t_vector3	**cartesian_to_iso(t_vector3 **coord, t_parse *parser)
{
	int			x;
	int			y;
	t_vector3	**coord_iso;

	y = 0;
	coord_iso = (t_vector3 **)malloc(sizeof(t_vector3 *) * parser->y + 1);
	printf("isometrique :\n");
	while (y < parser->y)
	{
		coord_iso[y] = (t_vector3 *)malloc(sizeof(t_vector3) * parser->x[y] + 1);
		x = 0;
		while (x < parser->x[y])
		{
			coord_iso[y][x].x = (coord[y][x].x * 10 - coord[y][x].y * 10);
			coord_iso[y][x].y = ((coord[y][x].x * 10 + coord[y][x].y * 10) / 2);
			x++;
		}
		y++;
	}
	print_2D_array(coord_iso, parser->y, parser->x);
	free_2D_array(coord, parser->y);
	return (coord_iso);
}


