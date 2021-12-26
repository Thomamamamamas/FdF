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

#include "fdf.h"

void	draw_grid(t_program *prog, t_vector2 **coords, int **relief_colors, t_parse *parser)
{
	size_t	x;
	size_t	y;
	int		color;

	y = 0;
	while (y < parser->y)
	{
		x = 0;
		while (x < parser->x[y])
		{
			color = relief_colors[y][x];
			mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, coords[y][x].x + prog->marginx, coords[y][x].y + prog->marginy, color);
			x++;
		}
		y++;
	}
}

void	draw_line_bottom(t_program *prog, t_vector2 coord1, t_vector2 coord2, int color1, int color2)
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
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x + prog->marginx, y + prog->marginy, choose_color(color1, color2, 0));
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

void	draw_line_top(t_program *prog, t_vector2 coord1, t_vector2 coord2, int color1, int color2)
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
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x + prog->marginx, y + prog->marginy, choose_color(color1, color2, 1));
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

void	connect_points(t_program *prog, t_vector2 **coords, int **relief_colors, t_parse *parser)
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
				if (coords[y][x].y < coords[y][x + 1].y)
					draw_line_bottom(prog, coords[y][x], coords[y][x + 1], relief_colors[y][x], relief_colors[y][x + 1]);
				else
					draw_line_top(prog, coords[y][x], coords[y][x + 1], relief_colors[y][x], relief_colors[y][x + 1]);
			}
			if (y > 0)
			{
				if (coords[y][x].y < coords[y - 1][x].y)
					draw_line_bottom(prog, coords[y][x], coords[y - 1][x], relief_colors[y][x], relief_colors[y - 1][x]);
				else
					draw_line_top(prog, coords[y][x], coords[y - 1][x], relief_colors[y][x], relief_colors[y - 1][x]);
			}
			x++;
		}
		y++;
	}
}
