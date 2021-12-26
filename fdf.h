/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:37:15 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 17:56:34 by tcasale          ###   ########.fr       */
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

# define RAD30 0.523599
# define RAD120 2.0944

# define COLOR_MAX6	0x00770191	//VIOLET
# define COLOR_MAX5	0x00FF0101	//ROUGE
# define COLOR_MAX4	0x00FF5523	//ROUGE-ORANGE
# define COLOR_MAX3	0x00FF9623	//ORANGE
# define COLOR_MAX2	0x00FFC323	//JAUNE ORANGE
# define COLOR_MAX1	0x00FFFF23	//JAUNE
# define COLOR_0	0x00FFFFFF	//BLANC
# define COLOR_MIN1	0x0096FF23	//JAUNE VERT
# define COLOR_MIN2	0x0001AF01	//VERT
# define COLOR_MIN3	0x00019687	//VERT BLEU
# define COLOR_MIN4	0x000164FF	//BLEU
# define COLOR_MIN5	0x004B01FF	//BLEU VIOLET
# define COLOR_MIN6	0x00A001FF	//VIOLET

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
	int		relief_medium_high;
	int		relief_medium;
	int		relief_medium_low;
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
t_vector3	**get_cartesian_coord(char **map, t_parse *parser);
t_vector2	**cartesian_to_iso(t_vector3 **coords, t_parse *parser);
int			**get_relief_color(t_program *color, t_vector3 **coord_carts, t_parse *parser);

//utils
void		free_vector3_array(t_vector3 **array, size_t line);
void		free_vector2_array(t_vector2 **array, size_t line);
void		set_relief_dimension(t_program *prog, t_vector3 **coords, t_parse *parser);

//drawing
void		draw_grid(t_program *prog, t_vector2 **coords, int **relief_colors, t_parse *parser);
void		draw_line_bottom(t_program *prog, t_vector2 coord1, t_vector2 coord2, int color1, int color2);
void		draw_line_top(t_program *prog, t_vector2 coord1, t_vector2 coord2, int color1, int color2);
void		connect_points(t_program *prog, t_vector2 **coords, int **relief_colors, t_parse *parser);

//color
int			choose_color(int color1, int color2, int direction);
int			get_color_id(int color);
int			swap_color(int color, int direction);

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
