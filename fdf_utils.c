/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:19:48 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/19 13:44:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_vector3_array(t_vector3 **array, size_t line)
{
	line--;
	while (line > 0)
		free(array[line--]);
	free(array);
}

void	free_vector2_array(t_vector2 **array, size_t line)
{
	line--;
	while (line > 0)
		free(array[line--]);
	free(array);
}
