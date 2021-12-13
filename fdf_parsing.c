/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:54:45 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/13 15:23:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

//Compte le nombre de ligne du fichier
size_t	number_of_line(char *file)
{
	int		fd;
	size_t	line;
	char	caracter;
	char	last_caracter;

	fd = open(file, O_RDWR);
	last_caracter = '\0';
	if (fd < 0)
		return (0);
	line = 0;
	while (read(fd, &caracter, 1) > 0)
	{
		if (caracter == '\n')
			line++;
		last_caracter = caracter;
	}
	close(fd);
	return (line);
}

//Recupere la map est la stock dans un array 2D
char	**parse_map(char *file, t_parse *parser)
{
	char	**height_array;
	char	*str;
	int	fd;
	int	i;
	int	is_parsing;
	int	line;

	fd = open(file, O_RDWR);
	i = 0;
	is_parsing = 1;
	parser->y = number_of_line(file);
	parser->x = (size_t *)malloc(sizeof(size_t) * parser->y + 1);
	ft_memset(parser->x, 0, parser->y);
	height_array = (char **)malloc(sizeof(char *) * parser->y + 1);
	while (is_parsing)
	{
		str = get_next_line(fd);
			if (!str)
				is_parsing = 0;
			else
			{
				parser->x[i] = count_nbr(str);
				height_array[i] = ft_strdup(str);
			}
		i++;
	}
	return (height_array);
}

//renvoie la taille d'un array 2 dimension
size_t	len_2d_char_array(char **array)
{
	int	n;

	n = 0;
	while (array[n] != '\0')
		n++;
	return (n);
}

//renvoie le nombre d'entier dans la chaine str
size_t	count_nbr(char *str)
{
	int		n;
	size_t	len;

	n = 0;
	len = 0;
	while (str[n])
	{
		if (str[n] == '-')
		{
			if (str[n + 1] && ft_isdigit(str[n + 1] ))
			{
				len++;
				n++;
				while (str[n + 1] && ft_isdigit(str[n + 1]))
					n++;
			}
		}
		else if (ft_isdigit(str[n]))
		{
			while (str[n + 1] && ft_isdigit(str[n + 1]))
				n++;
			len++;
		}
		n++;
	}
	return (len);
}

//renvoie un array des entiers de la chaine str
float	*get_nbr(char *str)
{
	int	n;
	int	i;
	float	*nb_array;

	nb_array = (float *)malloc(sizeof(float) * count_nbr(str) + 1);
	ft_memset(nb_array, 0, count_nbr(str));
	n = 0;
	i = 0;
	while (str[n])
	{
		if (str[n] == '-')
		{
			if (str[n + 1] && ft_isdigit(str[n + 1]))
			{
				nb_array[i++] = (float)ft_atoi(&str[n]);
				while (str[n + 1] && ft_isdigit(str[n + 1]))
					n++;
			}
		}
		else if (ft_isdigit(str[n]))
		{
			nb_array[i++] = (float)ft_atoi(&str[n]);
			while (str[n + 1] && ft_isdigit(str[n + 1]))
				n++;
		}
		n++;
	}
	return (nb_array);
}
