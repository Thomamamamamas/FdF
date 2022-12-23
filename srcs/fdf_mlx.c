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

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->prog.mlx, fdf->prog.win);
	exit(0);
	return (-1);
}

void	change_colorset(t_fdf *fdf)
{
	if (fdf->colorset_id == 2)
		fdf->colorset_id = 0;
	else
		fdf->colorset_id = fdf->colorset_id + 1;
	fdf->colorset = assign_colorset(fdf->colorset_id);
	get_matrix_colors(fdf);
	mlx_clear_window(fdf->prog.mlx, fdf->prog.win);
	draw_grid(fdf);
	connect_points(fdf);
}

int	key_pressed(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_CODE_ESC)
		close_window(fdf);
	if (keycode == KEY_CODE_C)
		change_colorset(fdf);
	return (0);
}
