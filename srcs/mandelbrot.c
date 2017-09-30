/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:26:12 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 00:20:35 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	mandel_coord(t_mlx *mlx)
{
	int		i;
	double	stand;
	
	i = 0;
	CR = COORDX / Z + XNEG;
	CI = COORDY / Z + YNEG;
	ZI = 0;
	ZR = 0;
	while ((pow(ZR, 2) - pow(ZI, 2)) < 4 && i < 50)
	{
		stand = ZR;
		ZR = pow(ZR, 2) - pow(ZI, 2) + CR;
		ZI = 2 * ZI * stand + CI;
		i++;
	}
	if (i == 50)
		image_set_pixel(mlx);	
	return;
}

void	mandel_maths(t_mlx *mlx)
{
	
	XNEG = -2.1;
	XPOS = 0.6;
	YNEG = -1.2;
	YPOS = 1.2;
	Z = 250;
	FX = (XPOS - XNEG) * Z;
	FY = (YPOS - YNEG) * Z;
	COORDX = 0;
	while (COORDX < FX)
	{
		COORDY = 0;
		while (COORDY < FY)
		{
			mandel_coord(mlx);
			COORDY++;
		}
		COORDX++;
	}
	return;
}
