/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:43:09 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/03 22:52:38 by ofranco          ###   ########.fr       */
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
		mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		mlx->image = new_image(mlx);
		julia_maths(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	}
	return (0);
}

int		key_func(int keycode, t_mlx *mlx)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		mlx_free(mlx);
	return (0);
}

int		mouse_func(int button, int x, int y, t_mlx *mlx)
{
	if (mlx)
		printf("button=%d x=%d y=%d\n", button, x, y);
	if (button == 1)
	{
		Z = 1.59;
		I_MAX += 20;
		printf("coucou?\n");
		mlx_clear_window(mlx->mlx, mlx->win);
		delete_image(mlx);
		mlx->image = new_image(mlx);
		printf("allooo ?\n");
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


