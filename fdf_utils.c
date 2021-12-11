/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:54:45 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/11 18:07:22 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	*parse_line(char *str)
{
	size_t	n;
	size_t	m;
	int		tmp;

	n = 0;
	m = 0;
	nb_array = (int *)malloc(sizeof(int) * ft_strlen(str) + 1);
	while (str[m])
	{
		if (ft_isdigit(str[m]) || str[m] == '-')
		{
			nb_array[n] = ft_atoi(&str[m]);
			tmp = nb_array[n];
			while (tmp / 10 > 0)
			{
				tmp = tmp / 10;
				m++;
			}
			n++;
		}
		m++;
	}
	return (n);
}

int	**array_concatenate(int **array1, int *array2)
{
	
}

int	**parse_map(char *file)
{
	int	**nb_array;
	int	tmp_array;
	int	fd;
	int	is_parsing;

	fd = open(file, O_RDWR);
	is_parsing = 1;
	while (is_parsing)
	{
		str = get_next_lie(fd)
			if (!str)
				is_parsing = 0;
		tmp_array = parse_line(str);
		nb_array = array_concatenate(nb_array, tmp_array);
	}
	return (nb_array);
}
