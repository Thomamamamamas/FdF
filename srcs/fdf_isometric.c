/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:15:57 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 17:00:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"
#include <stdio.h>

void	get_isometric_coords(t_fdf *fdf)
{
	int	n;
	int	m;
	int	**c;
	int	**res;

	n = 0;
	fdf->isometric = malloc_2d_t_vector2(fdf->matrix_line, fdf->matrix_col);
	while (n < fdf->matrix_line)
	{
		m = 0;
		while (m < fdf->matrix_col[n])
		{
			c = get_y_rotation_matrix(fdf, n, m);
			res = get_x_rotation_matrix(n, m);
			fdf->isometric[n][m].x = res[0][0];
			fdf->isometric[n][m].y = res[1][0];
			free(c);
			free(res);
			m++;
		}
		n++;
	}
}

//res = r_m1 * r_m2 * a
int	**get_y_rotation_matrix(t_fdf *fdf, int n, int m)
{
	int	**r_m1;
	int	**r_m2;
	int	**a;
	int	**res;

	r_m1 = get_first_y_rotation_matrix();
	r_m2 = get_second_y_rotation_matrix();
	a = malloc_matrix(4, 2);
	a[0][0] = n;
	a[1][0] = m;
	a[2][0] = fdf->cartesian[n][m];
	res = multiply_matrix_3x3(multiply_matrix_3x3(r_m1, r_m2, 3), a, 1);
	free(a);
	free(r_m1);
	free(r_m2);
	return (res);
}

//res = r_m1 * c
int	**get_x_rotation_matrix(int n, int m)
{
	int	**r_m1;
	int	**a;
	int	**res;

	r_m1 = get_first_x_rotation_matrix();
	a = malloc_matrix(4, 1);
	a[0][0] = n;
	a[1][0] = m;
	a[2][0] = 0;
	res = multiply_matrix_3x3(r_m1, a, 1);
	free(a);
	free(r_m1);
	return (res);
}