/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:00:29 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/26 17:57:36 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	choose_color(int color1, int color2, int direction)
{
	int	id_color1;
	int	id_color2;

	id_color1 = get_color_id(color1);
	id_color2 = get_color_id(color2);
	if (direction == 1)
	{
		if (id_color1 > id_color2)
			return (swap_color(color1, direction));
		else
			return (color1);
	}
	else
	{
		if (id_color1 < id_color2)
			return(swap_color(color1, direction));
		else
			return (color1);
	}
}

int	get_color_id(int color)
{
	if (color == COLOR_MAX6)
		return (6);
	if (color == COLOR_MAX5)
		return (5);
	if (color == COLOR_MAX4)
		return (4);
	if (color == COLOR_MAX3)
		return (3);
	if (color == COLOR_MAX2)
		return (2);
	if (color == COLOR_MAX1)
		return (1);
	if (color == COLOR_MIN1)
		return (-1);
	if (color == COLOR_MIN2)
		return (-2);
	if (color == COLOR_MIN3)
		return (-3);
	if (color == COLOR_MIN4)
		return (-4);
	if (color == COLOR_MIN5)
		return (-5);
	if (color == COLOR_MIN6)
		return (-6);
	return (0);
}

int	swap_color(int color, int direction)
{
	if (direction == 1)
	{
		if (color == COLOR_MIN6)
			return (COLOR_MIN4);
		else if (color == COLOR_MIN4)
			return (COLOR_MIN2);
		else if (color == COLOR_MIN2)
			return (COLOR_0);
		else if (color == COLOR_0)
			return (COLOR_MAX2);
		else if (color == COLOR_MAX2)
			return (COLOR_MAX4);
		else if (color == COLOR_MAX4)
			return (COLOR_MAX6);
	}
	else
	{
		if (color == COLOR_MAX6)
			return (COLOR_MAX4);
		else if (color == COLOR_MAX4)
			return (COLOR_MAX2);
		else if (color == COLOR_MAX2)
			return (COLOR_0);
		else if (color == COLOR_0)
			return (COLOR_MIN2);
		else if (color == COLOR_MIN2)
			return (COLOR_MIN4);
		else if (color == COLOR_MIN4)
			return (COLOR_MIN6);
	}
	return (color);
}
