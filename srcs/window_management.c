/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:03:30 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/04 16:03:37 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"

void	init_window(t_fdf *fdf)
{
	get_window_size(fdf);
	get_margins(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->prg.width, fdf->prg.height, "FdF");
}

void	get_window_size(t_fdf *fdf)
{
	while (fdf->prg.width > 1920 || fdf->prg.height > 1080)
	{
		get_margins(fdf);
		if (try_adapt_grid_size(fdf) == 0)
		{
			if (fdf->prg.width > 1920)
				fdf->prg.width = 1920;
			if (fdf->prg.height > 1080)
				fdf->prg.height = 1080;
		}
		else
		{
			fdf->prg.width = fdf->right - fdf->left + fdf->prg.grid * 2;
			fdf->prg.height = fdf->bottom - fdf->top + fdf->prg.grid * 2;
		}
	}
}

void	get_margins(t_fdf *fdf)
{
	int	tmp;

	if (fdf->left < 0 || fdf->right > fdf->prg.width)
	{
		if (fdf->left < fdf->prg.grid)
			fdf->prg.marginx = fabs(fdf->left) + fdf->prg.grid * 4;
		else if (fdf->right > fdf->prg.width)
		{
			tmp = fdf->prg.marginx - fdf->prg.grid;
			fdf->prg.marginx = tmp - (fdf->right - fdf->prg.width);
		}
	}
	if (fdf->top < 0 || fdf->bottom > fdf->prg.height)
	{
		if (fdf->top < fdf->prg.grid)
			fdf->prg.marginy = fabs(fdf->top) + fdf->prg.grid * 4;
		else if (fdf->bottom > fdf->prg.height)
		{
			tmp = fdf->prg.marginy - fdf->prg.grid;
			fdf->prg.marginy = tmp - (fdf->bottom - fdf->prg.height);
		}
	}
	convert_coords(fdf);
	get_matrix_limits(fdf);
}

int	try_adapt_grid_size(t_fdf *fdf)
{
	if (fdf->prg.grid > 2)
	{
		fdf->prg.grid--;
		convert_coords(fdf);
		get_matrix_limits(fdf);
		return (1);
	}
	return (0);
}
