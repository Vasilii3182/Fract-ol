/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:43:09 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:02:31 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		mouse_movement(int x, int y, t_mlx *mlx)
{
	if (NAME[0] == 'J')
	{
		CR = x / (W_WIDTH / (XPOS - XNEG)) + XNEG;
		CI = y / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
		//mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		mlx->image = new_image(mlx);
		julia_maths(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
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
	printf("button=%d\n", button);
	if (button == 1)
	{
		printf("zoom\n");
		BUTTON = 1;
		Z = 1.11;
		I_MAX += 10;
		//mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		mlx->image = new_image(mlx);
		re_calc_fractal(mlx, x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	}
	if (button == 4)
	{
		printf("dezooom\n");
		BUTTON = 4;
		Z = 1.11;
		if (I_MAX > I_REF)
			I_MAX -= 10;
		//mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		mlx->image = new_image(mlx);
		re_calc_fractal(mlx, x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	}
	return (0);
}

int		redraw_func(void *param)
{
	if (param == NULL)
		;
	return (0);
}
