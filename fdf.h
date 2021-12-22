/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:37:15 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/22 18:04:14 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_LENGHT	10
# define WINDOW_HEIGHT	10

# define KEY_PRESSED	2
# define KEY_RELEASED	3
# define MOUSE_PRESSED	4
# define WINDOW_CLOSED	17

# define KEY_CODE_ESC	53

# define GRID_SIZEX		50
# define GRID_SIZEY		50
# define MARGINY		20
# define MARGINX		20

# define COLOR_HIGHER	0x00C800FC
# define COLOR_HIGH		0x00FA3200
# define COLOR_MEDIUM_H	0x00FFFF00
# define COLOR_MEDIUM	0x00FFFFFF
# define COLOR_MEDIUM_L	0x0099CCFF
# define COLOR_LOW		0x0000C8FA
# define COLOR_LOWER	0x000014FA

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <math.h>

typedef struct	s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	int		marginx;
	int		marginy;
	int		relief_higher;
	int		relief_high;
	int		relief_medium;
	int		relief_low;
	int		relief_lower;
}				t_program;

typedef struct	s_parse
{
	size_t	*x;
	size_t	y;
}				t_parse;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

//parsing
size_t		number_of_line(char *file);
char		**parse_map(char *file, t_parse *parser);
size_t		len_2d_char_array(char **array);
size_t		count_nbr(char *str);
float		*get_nbr(char *str);

//isometric/cartesian
t_vector3	**get_cartesian_coord(char **height_array, t_parse *parser);
t_vector2	**cartesian_to_iso(t_vector3 **cord, t_parse *parser);
int			**relief_color(t_program *color, t_vector3 **coord_cart_array, t_parse *parser);

//utils
void		free_vector3_array(t_vector3 **array, size_t line);
void		free_vector2_array(t_vector2 **array, size_t line);
void		set_relief_dimension(t_program *prog, t_vector3 **coord_array, t_parse *parser);

//drawing
void		draw_grid(t_program *prog, t_vector2 **coord_array, int **relief_color_array, t_parse *parser);
void		draw_line_bottom(t_program *prog, t_vector2 coord1, t_vector2 coord2);
void		draw_line_top(t_program *prog, t_vector2 coord1, t_vector2 coord2);
void		connect_points(t_program *prog, t_vector2 **coord_array, t_parse *parser);

//minilibx interaction
t_program	init_window(t_parse *parser);
int			close_window(t_program *prog);
int			key_pressed(int keycode, t_program *prog);

//debug
void		print_vector3(t_vector3 vector);
void		print_vector2(t_vector2 vector);
void		print_vector3_array(t_vector3 **array, size_t line, size_t *column);
void		print_vector2_array(t_vector2 **array, size_t line, size_t *column);

#endif
