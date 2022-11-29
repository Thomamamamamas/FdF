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
#include "../headers/fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc < 2)
		return (-1);
	fdf = init_fdf(argv[1]);
	printf("error code = %d\n", fdf.prog.error_code);
	if (fdf.prog.error_code == 0)
	{
		init_window(&fdf);
		draw_grid(&fdf);
		connect_points(&fdf);
		//if pressed a key
		mlx_hook(fdf.prog.win, KEY_PRESSED, 0, &key_pressed, &fdf.prog);
		//if closed window
		mlx_hook(fdf.prog.win, WINDOW_CLOSED, 0, &close_window, &fdf.prog);
		mlx_loop(fdf.prog.mlx);
	}
	if (fdf.prog.error_code != 0)
		error_gestion(&fdf);
	end_fdf(&fdf);
}
