/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:15:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/12 14:24:01 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_vector3	**get_cartesian_coord(char **height_array, t_parse *parser)
{
	t_vector3	vector3_tmp;
	t_vector3	**cart_coord_array;
	int			*nb_array;
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
		printf("{");
		while (x < parser->x[y])
		{
			vector3_tmp.x = x;
			vector3_tmp.y = y;
			vector3_tmp.z = nb_array[x];
			printf("(%d, ", vector3_tmp.x);
			printf(" %d, ", vector3_tmp.y);
			printf("%d), ", vector3_tmp.z);
			cart_coord_array[y][x] = vector3_tmp;
			x++;
		}
		printf("}\n");
		y++;
	}
	return (cart_coord_array);
}

void	cartesian_to_iso(t_vector3 **coord, t_parse *parser)
{
	int		x;
	int		y;

	y = 0;
	printf("isometrique :\n");
	while (y < parser->y)
	{
		x = 0;
		printf("{ ");
		while (x < parser->x[y])
		{
			coord[y][x].x = coord[y][x].x - coord[y][x].y;
			coord[y][x].y = (coord[y][x].x + coord[y][x].y) / 2;
			printf("(%d, ", coord[y][x].x);
			printf(" %d, ", coord[y][x].y);
			printf("%d), ", coord[y][x].z);
			x++;
		}
		printf("}\n");
		y++;
	}
}
