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

void	change_colorset(t_fdf *fdf)
{
	if (fdf->colorset_id == 2)
		fdf->colorset_id = 0;
	else
		fdf->colorset_id = fdf->colorset_id + 1;
	fdf->colorset = assign_colorset(fdf->colorset_id);
	get_matrix_colors(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	connect_points(fdf);
}

void	moove_matrix(t_fdf *fdf, int keycode)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
		{
			if (keycode == CODE_W)
				fdf->mx[y][x].y = fdf->mx[y][x].y - MOOVE_Y;
			else if (keycode == CODE_S)
				fdf->mx[y][x].y = fdf->mx[y][x].y + MOOVE_Y;
			else if (keycode == CODE_D)
				fdf->mx[y][x].x = fdf->mx[y][x].x + MOOVE_X;
			else if (keycode == CODE_A)
				fdf->mx[y][x].x = fdf->mx[y][x].x - MOOVE_X;
			x++;
		}
		y++;
	}
	redraw_matrix(fdf);
}

int	redraw_matrix(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	connect_points(fdf);
	return (0);
}

int	key_pressed(int code, t_fdf *fdf)
{
	if (code == CODE_ESC)
		end_fdf(fdf);
	if (code == CODE_C)
		change_colorset(fdf);
	if (code == CODE_W || code == CODE_S || code == CODE_A || code == CODE_D)
		moove_matrix(fdf, code);
	return (0);
}
