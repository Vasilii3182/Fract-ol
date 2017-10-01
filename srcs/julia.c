/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:25:29 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 14:00:02 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_coords(t_mlx *mlx)
{
	int     i;
	double  stand;

	i = 0;
	ZR = COORDX / Z + XNEG;
	ZI = COORDY / Z + YNEG;
	CI = 0.285;
	CR = 0.001;
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

void	julia_maths(t_mlx *mlx)
{
	XNEG = -1.5;
	XPOS = 1.5;
	YNEG = -1.5;
	YPOS = 1.5;
	Z = 300;
	FX = (XPOS - XNEG) * Z;
	FY = (YPOS - YNEG) * Z;
	COORDX = 0;
	while (COORDX < FX)
	{
		COORDY = 0;
		while (COORDY < FY)
		{
			julia_coords(mlx);
			COORDY++;
		}
		COORDX++;
	}
	return;
}
