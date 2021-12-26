/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 18:18:53 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_program	init_window(t_parse *parser)
{
	size_t		x;
	size_t		y;
	size_t		n;
	t_program	prog;

	x = 0;
	y = parser->y;
	n = 0;
	while (n < y)
	{
		if (parser->x[n] > x)
			x = parser->x[n];
		n++;
	}
	prog.mlx_ptr = mlx_init();
	prog.win_height = (GRID_SIZEY * 1.75) * y + MARGINY;
	prog.win_width = (GRID_SIZEX * 1.75) * x + MARGINX;
	prog.marginx = prog.win_width / 2 - GRID_SIZEX * 2;
	prog.marginy = MARGINY * y;
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, prog.win_width, prog.win_height, "FdF");
	prog.relief_higher = 10;
	prog.relief_high = 5;
	prog.relief_medium_high = 2;
	prog.relief_medium = 0;
	prog.relief_medium_low = -2;
	prog.relief_low = -5;
	prog.relief_lower = -10;
	return(prog);
}

int	close_window(t_program *prog)
{
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	exit(0);
	return (-1);
}


int	key_pressed(int keycode, t_program *prog)
{
	if (keycode == KEY_CODE_ESC)
		close_window(prog);
	return (0);
}
