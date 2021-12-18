/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/18 18:08:33 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, MARGIN * x * GRID_SIZE, MARGIN * y * GRID_SIZE, "FdF");
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
