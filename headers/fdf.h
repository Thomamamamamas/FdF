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

# define ALPHA			0.610865238
# define BETA			0.785398

# define WHITE			0x0FFFFFF

#include "../srcs/minilibx/mlx.h"
#include "../srcs/libft/libft.h"
#include "../srcs/get_next_line/get_next_line.h"
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

typedef struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

typedef struct	s_fdf
{
	int			**cartesian;
	t_vector2	**isometric;
	int			matrix_line;
	int			*matrix_col;
	t_program	prog;
}				t_fdf;


//parsing
int			number_of_line(char *file);
void		parse_map(t_fdf *fdf, char *file);
size_t		len_2d_char_array(char **array);
void		parse_actual_line(t_fdf *fdf, char *str, int i);

//isometric/cartesian
void		get_isometric_coords(t_fdf *fdf);
int			**get_y_rotation_matrix(t_fdf *fdf, int n, int m);
int			**get_x_rotation_matrix(int n, int m);

//matrix
int			**malloc_matrix(int line, int col);
int			**multiply_matrix_3x3(int **m1, int **m2, int col2);
int			**get_first_y_rotation_matrix(void );
int			**get_second_y_rotation_matrix(void );
int			**get_first_x_rotation_matrix(void );

//utils
void		end_fdf(t_fdf *fdf);
t_vector2	**malloc_2d_t_vector2(int line, int *col);
void		free_int_2d_array(int	**array, int line);
void		free_vector2_array(t_vector2 **array, size_t line);
void		set_relief_dimension(t_fdf *fdf);

//drawing
void		draw_grid(t_fdf *fdf, t_vector2 **coords);
void		draw_line_bottom(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2);
void		draw_line_top(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2);
void		connect_points(t_fdf *fdf, t_vector2 **coords);

//minilibx interaction
t_program	init_window();
int			close_window(t_program *prog);
int			key_pressed(t_program *prog, int keycode);

//debug
void		print_vector2(t_vector2 vector);
void		print_vector2_array(t_vector2 **array, size_t line, size_t *column);

#endif
