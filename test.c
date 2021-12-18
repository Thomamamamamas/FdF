/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:13:53 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/18 15:53:53 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main()
{
	t_program	prog;
	t_vector3	**coord_array;
	t_parse		parser;

	prog = init_window();
	coord_array = (t_vector3 **)malloc(sizeof(t_vector3 *) * 3);
	coord_array[0] = (t_vector3 *)malloc(sizeof(t_vector3) * 3);
	coord_array[0][0].x = 100;
	coord_array[0][0].y = 100;
	coord_array[0][0].z = 0;
	coord_array[0][1].x = 500;
	coord_array[0][1].y = 50;
	coord_array[0][1].z = 0;
	coord_array[1] = (t_vector3 *)malloc(sizeof(t_vector3) * 3);
	coord_array[1][0].x = 100;
	coord_array[1][0].y = 500;
	coord_array[1][0].z = 0;
	coord_array[1][1].x = 500;
	coord_array[1][1].y = 500;
	coord_array[1][1].z = 0;
	parser.y = 2;
	parser.x = (size_t *)malloc(sizeof(size_t) * 3);
	parser.x[0] = 2;
	parser.x[1] = 2;
	draw_grid(&prog, coord_array, &parser);
	connect_points(&prog, coord_array, &parser);
	mlx_loop(prog.mlx_ptr);
}
