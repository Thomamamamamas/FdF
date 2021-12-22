/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:18:12 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/22 17:58:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	prog;
	t_parse		parser;
	char		**height_array;
	t_vector3	**coord_cart_array;
	int			**relief_color_array;
	t_vector2	**coord_array;

	if (argc < 2)
		return (-1);
	height_array = parse_map(argv[1], &parser);
	coord_cart_array = get_cartesian_coord(height_array, &parser);
	coord_array = cartesian_to_iso(coord_cart_array, &parser);
	prog = init_window(&parser);
	set_relief_dimension(&prog, coord_cart_array, &parser);
	relief_color_array = relief_color(&prog, coord_cart_array, &parser);
	draw_grid(&prog, coord_array, relief_color_array, &parser);
	//connect_points(&prog, coord_array, relief_color_array, &parser);
	//if pressed a key
	mlx_hook(prog.win_ptr, KEY_PRESSED, 0, &key_pressed, &prog);
	//if closed window
	mlx_hook(prog.win_ptr, WINDOW_CLOSED, 0, &close_window, &prog);
	mlx_loop(prog.mlx_ptr);
	free(height_array);
}
