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

# define WHITE			0x0FFFFFF

# define GRIDX			50
# define GRIDY			50
# define MARGINX		300
# define MARGINY		300

#include "../srcs/mlx/mlx.h"
#include "../srcs/libftprintf/ft_printf.h"
#include "../srcs/libftprintf/libft/libft.h"
#include "../srcs/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <math.h>

typedef struct	s_program
{
	void	*mlx;
	void	*win;
	float	win_height;
	float	win_width;
	int		spacex;
	int		spacey;
	int		error_code;
	float	marginx;
	float	marginy;
	int		gridx;
	int		gridy;
	float	max_height;
	float	max_width;
	float	max_size;
}				t_program;

typedef struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef struct	s_fdf
{
	t_vector3	**coords;
	t_vector2	**matrix;
	int			matrix_line;
	int			*matrix_col;
	float		high;
	float		low;
	float		left;
	float		right;
	t_program	prog;
}				t_fdf;

//parsing
int			number_of_line(char *file);
void		parse_map(t_fdf *fdf, int fd);
void		allocate_matrix(t_fdf *fdf, char *file);
void		allocate_actual_line(t_fdf *fdf, char *str, int y);

//parsing2
void		parse_actual_line(t_fdf *fdf, char *str, int y);
void		parse_actual_coord(t_fdf *fdf, char *str, int x, int y);
void		actual_coord_to_iso(t_fdf *fdf, int x, int y, int z);
void		convert_coords(t_fdf *fdf);
void		parse_windows_info(t_fdf *fdf);

//utils
t_fdf		init_fdf(char *file);
void		end_fdf(t_fdf *fdf);
void		free_vector2_array(t_vector2 **array, size_t line);
void		get_matrix_limits(t_fdf *fdf);
//drawing
void		draw_grid(t_fdf *fdf);
void		bresenham_line(t_fdf *fdf, t_vector2 coord1, t_vector2 coord2);
void		connect_points(t_fdf *fdf);
//error
void		error_gestion(t_fdf *fdf);
// window management
void		init_window(t_fdf *fdf);
void		get_all_windows_value(t_fdf *fdf);
void		update_window_value(t_fdf *fdf);
int			check_if_window_is_valid(t_fdf *fdf);
int			check_visible_point(t_fdf *fdf, int n);
// window management2
void		ajust_window_size(t_fdf *fdf);
//minilibx fdf
int			close_window(t_program *prog);
int			key_pressed(t_program *prog, int keycode);
//debug
void		print_vector2(t_vector2 vector);
void		print_vector2_array(t_vector2 **array, size_t line, size_t *column);

#endif
