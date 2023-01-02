/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:33:38 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/19 13:39:36 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"
#include <stdio.h>

void	print_vector2(t_v2 vector)
{
	printf("(%.2f, %.2f) color : ", vector.x, vector.y);
	print_rgb(vector.color);
}

void	print_vector3(t_v3 vector)
{
	printf("(%.2f, %.2f, %.2f) color : ", vector.x, vector.y, vector.z);
	print_rgb(vector.color);
}

void	print_rgb(t_rgb color)
{
	printf("(R: %d G: %d B: %d)\n", color.r, color.g, color.b);
}

void	print_mx(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	printf("__________MATRIX INFO__________\n");
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf-> mx_col[y])
		{
			print_vector2(fdf->mx[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("right : %.2f\n", fdf->right);
	printf("left : %.2f\n", fdf->left);
	printf("high : %.2f\n", fdf->top);
	printf("low : %.2f\n", fdf->bottom);
	printf("smallest : %.2f\n", fdf->smallest);
	printf("medium : %.2f\n", fdf->medium);
	printf("largest : %.2f\n", fdf->largest);
	printf("_______________________________\n");
}

void	print_coords(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mx_line)
	{
		x = 0;
		while (x < fdf-> mx_col[y])
		{
			print_vector3(fdf->coords[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_window_info(t_fdf *fdf)
{
	printf("__________WINDOW INFO__________\n");
	printf("win height = %.2f\n", fdf->prg.height);
	printf("win width = %.2f\n", fdf->prg.width);
	printf("marginx = %.2f\n", fdf->prg.marginx);
	printf("marginy = %.2f\n", fdf->prg.marginy);
	printf("grid = %d\n", fdf->prg.grid);
	printf("_______________________________\n");
}
