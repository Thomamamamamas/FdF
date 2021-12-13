/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:18:12 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/13 17:17:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	prog;
	t_parse		parser;
	int			fd;
	char		**height_array;
	t_vector3	**coord_array;
	int			is_parsing;

	if (argc < 2)
		return (-1);
	height_array = parse_map(argv[1], &parser);
	coord_array = get_cartesian_coord(height_array, &parser);
	cartesian_to_iso(coord_array, &parser);
	/*
	prog = init_window();
	draw_grid(coord_array, prog);
	//if pressed a key
	mlx_hook(prog.win_ptr, KEY_PRESSED, 0, &key_pressed, &prog);
	//if closed window
	mlx_hook(prog.win_ptr, WINDOW_CLOSED, 0, &close_window, &prog);
	mlx_loop(prog.mlx_ptr);
	free(height_array);
	*/
}
