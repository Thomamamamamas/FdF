/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:35:58 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/18 18:26:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_program *prog, t_vector3 **coord_array, t_parse *parser)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < parser->y)
	{
		x = 0;
		while (x < parser->x[y])
		{
			mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, coord_array[y][x].x, coord_array[y][x].y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_line_bottom(t_program *prog, t_vector3 coord1, t_vector3 coord2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	p;
	size_t	direction_y;

	dy = coord2.y - coord1.y;
	dx = coord2.x - coord1.x;
	y = coord1.y;
	x = coord1.x;
	p = 2 * dy - dx;
	while (x < coord2.x)
	{
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x, y, 0x00FFFFFF);
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

void	draw_line_top(t_program *prog, t_vector3 coord1, t_vector3 coord2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	p;
	size_t	direction_y;

	dy = coord1.y - coord2.y;
	dx = coord2.x - coord1.x;
	y = coord1.y;
	x = coord1.x;
	p = 2 * dy - dx;
	while (x < coord2.x)
	{
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x, y, 0x00FFFFFF);
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

void	connect_points(t_program *prog, t_vector3 **coord_array, t_parse *parser)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < parser->y)
	{
		x = 0;
		while (x < parser->x[y])
		{
			if (x + 1 < parser->x[y])
			{
				if (coord_array[y][x].y < coord_array[y][x + 1].y)
					draw_line_bottom(prog, coord_array[y][x], coord_array[y][x + 1]);
				else
					draw_line_top(prog, coord_array[y][x], coord_array[y][x + 1]);
			}
			if (y > 0)
			{
				if (coord_array[y][x].y < coord_array[y - 1][x].y)
					draw_line_bottom(prog, coord_array[y][x], coord_array[y - 1][x]);
				else
					draw_line_top(prog, coord_array[y][x], coord_array[y - 1][x]);
			}
			x++;
		}
		y++;
	}
}
