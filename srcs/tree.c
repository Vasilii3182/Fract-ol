/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 13:32:32 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 22:37:24 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	case1rosette(t_mlx *mlx, double *o)
{
	int i;

	i = 0;
	printf("case1\n");
	while (i < RX)
	{
		COORDX = o[0];
		COORDY = o[1];
		image_set_pixel(mlx);
		i++;
		o[0] += X_INCR;
		EX -= DY;
		if (EX < 0)
		{
			o[1] += Y_INCR;
			EX += DX;
		}
	}
	return ;
}

void	case2rosette(t_mlx *mlx, double *o)
{
	int i;

	i = 0;
	printf("case2\n");
	while (i < RY)
	{
		COORDX = o[0];
		COORDY = o[1];
		image_set_pixel(mlx);
		i++;
		o[1] += Y_INCR;
		EY -= DX;
		if (EY < 0)
		{
			printf("iplop\n");
			o[0] += X_INCR;
			EY += DY;
		}
	}
	return ;
}

void	line_tracer(t_mlx *mlx, double *o, double *newp)
{

	EY = fabs(newp[1] - o[1]);
	//printf("linetracer: newp[1]=%d | o[1]=%d | result = %d\n", newp[1], o[1], EY);
	EX = fabs(newp[0] - o[0]);
	//printf("linetracer: newp[0]=%d | o[0]=%d | result = %d\n", newp[0], o[0], EX);
	DX = 2 * EX;
	DY = 2 * EY;
	X_INCR = 1;
	Y_INCR = 1;
	RX = EX;
	RY = EY;
	if (o[0] > newp[0])
		X_INCR = -1;
	if (o[1] > newp[1])
		Y_INCR = -1;
	if (RX > RY)
		case1rosette(mlx, o);
	if (RX < RY)
		case2rosette(mlx, o);
	return ;
}

void    branch(t_mlx *mlx , double *o, double *newp, double len, double angle)
{
	if (len > 4)
	{
		o[0] = newp[0];
		o[1] = newp[1];
		newp[0] = o[0] + (int)(len * cos(M_PI_4));
		newp[1] = o[1] + (int)(len * sin(M_PI_4));
		line_tracer(mlx, o, newp);
		branch(mlx, o, newp, len * 0.67, angle * (0.5));
		//newp[0] = o[0] - len * cos(M_PI_4);
		//newp[1] = o[1] + (len * sin(M_PI_4) * (-1));
		//line_tracer(mlx, o, newp);
		//branch(mlx, tmp, newp, len * 0.67);
	}
	return;
}

//double	rotate(double angle)
//{

//}

void	trunk(t_mlx *mlx)
{
	double len;
	double *o;
	double *newp;
	double angle;

	if ((newp = (double*)malloc(sizeof(double) * 2)) == NULL)
		return;
	if ((o = (double*)malloc(sizeof(double) * 2)) == NULL)
		return;
	angle = M_PI_4;
	o[0] = 350;
	o[1] = 700;
	len = 150;
	newp[0] = o[0];
	newp[1] = o[1] - len;
	line_tracer(mlx, o, newp);
	len = len * 0.67;
	branch(mlx, o, newp, len, angle);
	free(o);
	free(newp);
	return;
}
