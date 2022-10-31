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

void	print_vector2(t_vector2 vector)
{
	printf("(%.2f, %.2f)", vector.x, vector.y);
}

void	print_vector2_array(t_vector2 **array, size_t line, size_t *column)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (n < line)
	{
	printf("{");
	m = 0;
		while (m < column[n])
		{
			print_vector2(array[n][m]);
			if (m + 1 != line)
				printf(", ");
			m++;
		}
		printf("}\n");
		n++;
	}
}
