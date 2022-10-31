#include "../headers/fdf.h"

int	**malloc_matrix(int line, int col)
{
	int	**res;
	int	n;

	res = (int **)malloc(sizeof(int *) * line);
	n = 0;
	while (n < line)
	{
		res[n] = (int *)malloc(sizeof(int) * col);
		n++;
	}
	return (res);
}

int	**multiply_matrix_3x3(int **m1, int **m2, int col2)
{
	int	**res;
	int	n;
	int	m;

	res = malloc_matrix(4, col2);
	n = 0;
	while (n < 3)
	{
		m = 0;
		res[n] = (int *)malloc(sizeof(int) * col2);
		while (m < col2)
		{
			res[n][m] = m1[n][0] * m2[0][m] + m1[n][1] * m2[1][m] + m1[n][2] * m2[2][m];
			m++;
		}
		n++;
	}
	return (res);
}

int	**get_first_y_rotation_matrix()
{
	int	**res;

	res = malloc_matrix(4, 3);
	res[0][0] = 1;
	res[0][1] = 0;
	res[0][2] = 0;
	res[1][0] = 0;
	res[1][1] = cos(ALPHA);
	res[1][2] = sin(ALPHA);
	res[2][0] = 0;
	res[2][1] = -sin(ALPHA);
	res[2][2] = cos(ALPHA);
	return (res);
}

int	**get_second_y_rotation_matrix()
{
	int	**res;

	res = malloc_matrix(4, 3);
	res[0][0] = cos(BETA);
	res[0][1] = 0;
	res[0][2] = -sin(BETA);
	res[1][0] = 0;
	res[1][1] = 1;
	res[1][2] = 0;
	res[2][0] = sin(BETA);
	res[2][1] = 0;
	res[2][2] = cos(BETA);
	return (res);
}

int	**get_first_x_rotation_matrix()
{
	int	**res;

	res = malloc_matrix(4, 3);
	res[0][0] = 1;
	res[0][1] = 0;
	res[0][2] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	res[1][2] = 0;
	res[2][0] = 0;
	res[2][1] = 0;
	res[2][2] = 0;
	return (res);
}