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
	t_v2	v;
	int		x;
	int		y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
		{
			v.x = fdf->mx[y][x].x;
			v.y = fdf->mx[y][x].y;
			v.color = fdf->mx[y][x].color;
			mlx_pixel_put(fdf->mlx, fdf->win, v.x, v.y, rgb_hex(v.color));
			x++;
		}
		y++;
	}
}

void	bresenham_line(t_fdf *fdf, t_v2 coord1, t_v2 coord2)
{
	t_v2	v1;
	t_v2	v2;
	t_v2	ev;

	v1.x = coord1.x;
	v1.y = coord1.y;
	v1.color = coord1.color;
	v2.x = coord2.x;
	v2.y = coord2.y;
	v2.color = coord2.color;
	ev.x = fabs(v2.x - v1.x);
	ev.y = fabs(v2.y - v1.y);
	if (ev.x > ev.y)
		bresenham_base_case(fdf, v1, v2, ev);
	else
		bresenham_inverse_case(fdf, v1, v2, ev);
}

void	bresenham_base_case(t_fdf *fdf, t_v2 v1, t_v2 v2, t_v2 ev)
{
	int		i;
	int		color;
	float	big_dx;
	t_v2	dv;

	dv.x = 2 * ev.x;
	dv.y = 2 * ev.y;
	big_dx = ev.x;
	i = 1;
	while (i <= big_dx)
	{
		color = line_color(v1.color, v2.color, i / big_dx);
		mlx_pixel_put(fdf->mlx, fdf->win, v1.x, v1.y, color);
		v1.x = bresenham_increment_v1(v1.x, v2.x);
		ev.x -= dv.y;
		if (ev.x < 0)
		{
			v1.y = bresenham_increment_v1(v1.y, v2.y);
			ev.x += dv.x;
		}
		i++;
	}
}

void	bresenham_inverse_case(t_fdf *fdf, t_v2 v1, t_v2 v2, t_v2 ev)
{
	int		i;
	int		color;
	float	big_dy;
	t_v2	dv;

	dv.x = 2 * ev.x;
	dv.y = 2 * ev.y;
	big_dy = ev.y;
	i = 1;
	while (i <= big_dy)
	{
		color = line_color(v1.color, v2.color, i / big_dy);
		mlx_pixel_put(fdf->mlx, fdf->win, v1.x, v1.y, color);
		v1.y = bresenham_increment_v1(v1.y, v2.y);
		ev.y -= dv.x;
		if (ev.y < 0)
		{
			v1.x = bresenham_increment_v1(v1.x, v2.x);
			ev.y += dv.y;
		}
		i++;
	}
}

void	connect_points(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf->mx_col[y])
		{
			if (x < fdf->mx_col[y] - 1)
			{
				bresenham_line(fdf, fdf->mx[y][x], fdf->mx[y][x + 1]);
			}
			if (y > 0 && fdf->mx_col[y - 1] > x)
			{
				bresenham_line(fdf, fdf->mx[y][x], fdf->mx[y - 1][x]);
			}
			x++;
		}
		y++;
	}
}
