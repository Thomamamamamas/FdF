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
#include "stdio.h"

void	draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->matrix_line)
	{
		x = 0;
		while (x < fdf->matrix_col[y])
		{
			mlx_pixel_put(fdf->prog.mlx, fdf->prog.win, fdf->matrix[y][x].x, fdf->matrix[y][x].y, WHITE);
			x++;
		}
		y++;
	}
}

void	bresenham_line(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2)
{
	float	x1 =  coord1.x, y1 = coord1.y;
	float	x2 = coord2.x, y2 = coord2.y;
	float	ex = fabs(x2 - x1);
	float 	ey = fabs(y2 - y1);
	float	dx = 2 * ex;
	float	dy = 2 * ey;
	float	DX = ex;
	float	DY = ey;
	int		i = 0;
	int		Xincr = 1;
	int		Yincr = 1;

	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	if (DX > DY)
	{
		while (i <= DX)
		{
			mlx_pixel_put(fdf->prog.mlx, fdf->prog.win, x1, y1, WHITE);	
			i++;
			x1 += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += Yincr;
				ex += dx;
			}
		}
	}
	else
	{
		while (i <= DY)
		{
			mlx_pixel_put(fdf->prog.mlx, fdf->prog.win, x1, y1, WHITE);	
			i++;
			y1 += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += Xincr;
				ey += dy;
			}
		}
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
			if (x < fdf->matrix_col[y] - 1)
			{
				bresenham_line(fdf, fdf->matrix[y][x], fdf->matrix[y][x + 1]);
			}
			if (y > 0 && fdf->matrix_col[y - 1] > x)
			{
				bresenham_line(fdf, fdf->matrix[y][x], fdf->matrix[y - 1][x]);
			}
			x++;
		}
		y++;
	}
}
