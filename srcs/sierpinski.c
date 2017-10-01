/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:08:50 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 12:22:21 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    sierpinski_coords(t_mlx *mlx)
{
	int     i;
	double  stand;

	i = 0;
	ZR = COORDX / Z + XNEG;
	ZI = COORDY / Z + YNEG;
	CI = 0.285;
	CR = 0.001;
	while ((pow(ZR, 2) - pow(ZI, 2)) < 4 && i < 150)
	{
		stand = ZR;
		ZR = pow(ZR, 2) - pow(ZI, 2) + CR;
		ZI = 2 * ZI * stand + CI;
		i++;
	}
	if (i == 150)
		image_set_pixel(mlx);
	return;
}

void    sierpinski_maths(t_mlx *mlx)
{
	XNEG = -1.5;
	XPOS = 1.5;
	YNEG = -1.5;
	YPOS = 1.5;
	Z = 150;
	FX = (XPOS - XNEG) * Z;
	FY = (YPOS - YNEG) * Z;
	COORDX = 0;
	while (COORDX < FX)
	{
		COORDY = 0;
		while (COORDY < FY)
		{
			sierpinski_coords(mlx);
			COORDY++;
		}
		COORDX++;
	}
	return;
}
