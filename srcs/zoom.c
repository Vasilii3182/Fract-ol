/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:13:52 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 12:58:09 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double strt, double end, double interp, t_mlx *mlx)
{
	if (mlx)
		return (strt + ((end - strt) * ((BUTTON == 1) ? interp : 1 / interp)));
	return (0);
}

void	applyzoom(t_mlx *mlx, double mousex, double mousey, double zoomfactor)
{
	double interpolation;

	interpolation = 1.0 / zoomfactor;
	XNEG = interpolate(mousex, XNEG, interpolation, mlx);
	YNEG = interpolate(mousey, YNEG, interpolation, mlx);
	XPOS = interpolate(mousex, XPOS, interpolation, mlx);
	YPOS = interpolate(mousey, YPOS, interpolation, mlx);
}

void	re_calc_fractal(t_mlx *mlx, int x, int y)
{
	double mousex;
	double mousey;

	mousex = (double)x / (W_WIDTH / (XPOS - XNEG)) + XNEG;
	mousey = (double)y / (W_HEIGHT / (YPOS - YNEG)) + YNEG;
	applyzoom(mlx, mousex, mousey, Z);
	if (NAME[0] == 'M')
		mandel_maths(mlx);
	if (NAME[0] == 'J')
		julia_maths(mlx);
	if (NAME[0] == 'B')
		burningship_maths(mlx);
}
