/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:26:12 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:35:51 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_coord(t_mlx *mlx)
{
	int		i;
	double	stand;

	i = 0;
	CR = COORDX / (W_WIDTH / (XPOS - XNEG)) + XNEG;
	CI = COORDY / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
	ZI = 0;
	ZR = 0;
	while ((ZR * ZR + ZI * ZI) < 4 && i < I_MAX)
	{
		stand = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * stand + CI;
		i++;
	}
	if (i == I_MAX)
		image_set_pixel(mlx, 0x000000);
	else
		image_set_pixel(mlx, ft_get_color(0, 0, (i * 255 / I_MAX)));
	return ;
}

void	mandel_maths(t_mlx *mlx)
{
	COORDX = 0;
	while (COORDX < W_WIDTH)
	{
		COORDY = 0;
		while (COORDY < W_HEIGHT)
		{
			mandel_coord(mlx);
			COORDY++;
		}
		COORDX++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	return ;
}
