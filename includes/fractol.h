/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:19:23 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 00:33:09 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "./../libft/libft.h"
#include "./../minilibx_macos/mlx.h"
#include <math.h>
#define CR mlx->params->c_r
#define CI mlx->params->c_i
#define ZR mlx->params->z_r
#define ZI mlx->params->z_i
#define Z mlx->params->zoom
#define FX mlx->params->framex
#define FY mlx->params->framey
#define XNEG mlx->params->x1
#define XPOS mlx->params->x2
#define YNEG mlx->params->y1
#define YPOS mlx->params->y2
#define COORDX mlx->params->x
#define COORDY mlx->params->y
#define BPP mlx->image->bpp

typedef	struct			s_image {

	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;
}						t_image;

typedef struct			s_equ {

	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	zoom;
	double	framex;
	double	framey;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		x;
	int		y;
}						t_equ;

typedef struct          s_mlx {

	void    *mlx;
	void    *win;
	t_image *image;
	t_equ   *params;
}                       t_mlx;

void	mandel_maths(t_mlx *mlx);
void	image_set_pixel(t_mlx *mlx);
void	*delete_image(t_mlx *mlx);
void	*new_image(t_mlx *mlx);
t_mlx	*initialize_win();
t_mlx	*mlx_free(t_mlx *mlx);
t_equ	*initialize();

#endif