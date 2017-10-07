/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:50:50 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:39:22 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_coords(t_mlx *mlx)
{
	int		i;
	double	stand;

	i = 0;
	ZR = 0;
	ZI = 0;
	CI = COORDY / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
	CR = COORDX / (W_WIDTH / (XPOS - XNEG)) + XNEG;
	while ((ZR * ZR + ZI * ZI) < 4 && i < I_MAX)
	{
		stand = ZR;
		ZR = fabs(ZR * ZR - ZI * ZI + CR);
		ZI = fabs(2 * ZI * stand + CI);
		i++;
	}
	if (i == I_MAX)
		image_set_pixel(mlx, 0x00000);
	else
		image_set_pixel(mlx, ft_get_color(0, i * 255 / I_MAX, 0));
	return ;
}

void	burningship_maths(t_mlx *mlx)
{
	COORDX = 0;
	while (COORDX < W_WIDTH)
	{
		COORDY = 0;
		while (COORDY < W_HEIGHT)
		{
			burningship_coords(mlx);
			COORDY++;
		}
		COORDX++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	return ;
}
