/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:25:29 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/04 16:50:54 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_coords(t_mlx *mlx)
{
	int		i;
	double	stand;

	i = 0;
	ZR = (double)COORDX / (W_WIDTH / (XPOS - XNEG)) + XNEG;
	ZI = (double)COORDY / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
	while ((ZR * ZR + ZI * ZI) < 4 && i < I_MAX)
	{
		stand = ZR;
		ZR = pow(ZR, 2) - pow(ZI, 2) + CR;
		ZI = 2 * ZI * stand + CI;
		i++;
	}
	if (i == I_MAX)
		image_set_pixel(mlx, 0x000000);
	else
		image_set_pixel(mlx, ft_get_color(i * 255 / I_MAX, 0, 0));
	return ;
}

void	julia_maths(t_mlx *mlx)
{
	COORDX = 0;
	while (COORDX < W_WIDTH)
	{
		COORDY = 0;
		while (COORDY < W_HEIGHT)
		{
			julia_coords(mlx);
			COORDY++;
		}
		COORDX++;
	}
	return ;
}
