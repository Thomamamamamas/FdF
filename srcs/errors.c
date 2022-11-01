#include "../headers/fdf.h"

void	error_gestion(t_fdf *fdf)
{
	if (fdf->prog.error_code == 1)
		ft_putstr_fd("Error: Can't open file", 2);
	else if (fdf->prog.error_code == 2)
		ft_putstr_fd("Error: Line in file not valid", 2);
}