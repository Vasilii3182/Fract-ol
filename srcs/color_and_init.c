/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:33:21 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 12:46:49 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burningship(t_mlx *mlx)
{
	XNEG = -3;
	XPOS = 2.5;
	YNEG = -2;
	YPOS = 3;
	I_MAX = 40;
	I_REF = I_MAX;
	Z = 1;
	burningship_maths(mlx);
}

void	init_julia(t_mlx *mlx)
{
	XNEG = -2.1;
	XPOS = 0.6;
	YNEG = -1.2;
	YPOS = 1.2;
	I_MAX = 40;
	I_REF = I_MAX;
	CI = 0.01;
	CR = 0.285;
	Z = 1;
	julia_maths(mlx);
}

void	init_mandel(t_mlx *mlx)
{
	XNEG = -2.1;
	XPOS = 0.6;
	YNEG = -1.2;
	YPOS = 1.2;
	I_MAX = 40;
	I_REF = I_MAX;
	Z = 1;
	mandel_maths(mlx);
}

int		ft_get_color(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}
