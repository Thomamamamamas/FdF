/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:18:12 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 18:20:21 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	prog;
	t_parse		parser;
	char		**map;
	t_vector3	**coord_carts;
	int			**relief_colors;
	t_vector2	**coords;

	if (argc < 2)
		return (-1);
	map = parse_map(argv[1], &parser);
	coord_carts = get_cartesian_coord(map, &parser);
	coords = cartesian_to_iso(coord_carts, &parser);
	prog = init_window(&parser);
	set_relief_dimension(&prog, coord_carts, &parser);
	relief_colors = get_relief_color(&prog, coord_carts, &parser);
	draw_grid(&prog, coords, relief_colors, &parser);
	connect_points(&prog, coords, relief_colors, &parser);
	//if pressed a key
	mlx_hook(prog.win_ptr, KEY_PRESSED, 0, &key_pressed, &prog);
	//if closed window
	mlx_hook(prog.win_ptr, WINDOW_CLOSED, 0, &close_window, &prog);
	mlx_loop(prog.mlx_ptr);
	free(map);
}
