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
#include "../headers/fdf.h"
#include <stdio.h>

void	init_window(t_fdf *fdf)
{

	fdf->prog.mlx_ptr = mlx_init();
	fdf->prog.marginy = 10;
	fdf->prog.marginx = 10;
	fdf->prog.gridx = 10;
	fdf->prog.gridy = 10;
	fdf->prog.spacex = 10;
	fdf->prog.spacey = 10;
	fdf->prog.win_height = 400;
	fdf->prog.win_width =  400;
	fdf->prog.win_ptr = mlx_new_window(fdf->prog.mlx_ptr, fdf->prog.win_width, fdf->prog.win_height, "FdF");
	fdf->prog.relief_higher = 10;
	fdf->prog.relief_high = 5;
	fdf->prog.relief_medium_high = 2;
	fdf->prog.relief_medium = 0;
	fdf->prog.relief_medium_low = -2;
	fdf->prog.relief_low = -5;
	fdf->prog.relief_lower = -10;
}

int	close_window(t_program *prog)
{
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	exit(0);
	return (-1);
}


int	key_pressed(t_program *prog, int keycode)
{
	if (keycode == KEY_CODE_ESC)
		close_window(prog);
	return (0);
}
