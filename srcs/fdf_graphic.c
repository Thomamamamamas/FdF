/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:35:58 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 18:23:48 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		ft_putstr_fd("\n", 2);
		while (x < fdf->matrix_col[y])
		{
			mlx_pixel_put(fdf->prog.mlx_ptr, fdf->prog.win_ptr, fdf->isometric[y][x].x * fdf->prog.spacex + 10, fdf->isometric[y][x].y * fdf->prog.spacey + 10, WHITE);
			x++;
		}
		y++;
	}
}

void	draw_line_bottom(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	p;

	dy = coord2.y - coord1.y;
	dx = coord2.x - coord1.x;
	y = coord1.y;
	x = coord1.x;
	p = 2 * dy - dx;
	while (x < coord2.x)
	{
		mlx_pixel_put(fdf->prog.mlx_ptr, fdf->prog.win_ptr, x + fdf->prog.marginx, y + fdf->prog.marginy, WHITE);
		if (p  >= 0)
		{
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			p = p + 2 * dy;
		}
		x++;
	}
}

void	draw_line_top(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	p;

	dy = coord1.y - coord2.y;
	dx = coord2.x - coord1.x;
	y = coord1.y;
	x = coord1.x;
	p = 2 * dy - dx;
	while (x < coord2.x)
	{
		mlx_pixel_put(fdf->prog.mlx_ptr, fdf->prog.win_ptr, x + fdf->prog.marginx, y + fdf->prog.marginy, WHITE);
		if (p  >= 0)
		{
			y--;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			p = p + 2 * dy;
		}
		x++;
	}
}

void	connect_points(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			if (x + 1 < fdf->matrix_col[y])
			{
				if (fdf->isometric[y][x].y < fdf->isometric[y][x + 1].y)
					draw_line_bottom(fdf, fdf->isometric[x][y], fdf->isometric[y][x + 1]);
				else
					draw_line_top(fdf, fdf->isometric[y][x], fdf->isometric[y][x + 1]);
			}
			if (y > 0)
			{
				if (fdf->isometric[y][x].y < fdf->isometric[y - 1][x].y)
					draw_line_bottom(fdf, fdf->isometric[y][x], fdf->isometric[y - 1][x]);
				else
					draw_line_top(fdf, fdf->isometric[y][x], fdf->isometric[y - 1][x]);
			}
			x++;
		}
		y++;
	}
}
