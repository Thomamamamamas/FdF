/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:37:15 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/12 14:24:11 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_PRESSED	2
# define KEY_RELEASED	3
# define MOUSE_PRESSED	4
# define WINDOW_CLOSED	17

# define KEY_CODE_ESC	53

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct	s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_program;

typedef struct	s_parse
{
	size_t	*x;
	size_t	y;
}				t_parse;

typedef struct	s_vector3
{
	int	x;
	int	y;
	int	z;
}				t_vector3;

size_t		number_of_line(char *file);
char		**parse_map(char *file, t_parse *parser);
size_t		len_2d_char_array(char **array);
size_t		count_nbr(char *str);
int			*get_nbr(char *str);

t_vector3	**get_cartesian_coord(char **height_array, t_parse *parser);
void		cartesian_to_iso(t_vector3 **cord, t_parse *parser);

int			close_window(t_program *prog);
int			key_pressed(int keycode, t_program *prog);

#endif
