/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:18:12 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/06 12:20:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
	{
		if (argc < 2)
			fdf.prg.error_code = 3;
		else
			fdf.prg.error_code = 4;
		error_gestion(&fdf);
		return (1);
	}
	fdf = init_fdf(argv[1]);
	if (fdf.prg.error_code == 0)
	{
		init_window(&fdf);
		draw_grid(&fdf);
		connect_points(&fdf);
		mlx_hook(fdf.win, KEY_PRESSED, 0, &key_pressed, &fdf);
		mlx_hook(fdf.win, ON_EXPOSE, 0, &redraw_matrix, &fdf);
		mlx_hook(fdf.win, ON_DESTROY, 0, &end_fdf, &fdf);
		mlx_loop(fdf.mlx);
	}
	error_gestion(&fdf);
	end_fdf(&fdf);
}
