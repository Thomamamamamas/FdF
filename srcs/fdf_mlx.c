/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 18:18:53 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"

int	close_window(t_program *prog)
{
	mlx_destroy_window(prog->mlx, prog->win);
	exit(0);
	return (-1);
}

int	key_pressed(t_program *prog, int keycode)
{
	if (keycode == KEY_CODE_ESC)
		close_window(prog);
	return (0);
}
