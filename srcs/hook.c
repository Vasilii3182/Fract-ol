/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:43:09 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:43:47 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_movement(int x, int y, t_mlx *mlx)
{
	if (NAME[0] == 'J')
	{
		CR = x / (W_WIDTH / (XPOS - XNEG)) + XNEG;
		CI = y / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
		delete_image(mlx);
		mlx->image = new_image(mlx);
		julia_maths(mlx);
	}
	return (0);
}

int		key_func(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		mlx_free(mlx);
	return (0);
}

int		mouse_func(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
	{
		BUTTON = 5;
		Z = 1.1;
		I_MAX += 5;
		delete_image(mlx);
		mlx->image = new_image(mlx);
		re_calc_fractal(mlx, x, y);
	}
	if (button == 4)
	{
		BUTTON = 4;
		Z = 1.1;
		if (I_MAX > I_REF)
			I_MAX -= 5;
		delete_image(mlx);
		mlx->image = new_image(mlx);
		re_calc_fractal(mlx, x, y);
	}
	return (0);
}

int		redraw_func(void *param)
{
	if (param == NULL)
		;
	return (0);
}
