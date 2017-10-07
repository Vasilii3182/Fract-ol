/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:19:23 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/04 15:30:14 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./../libft/libft.h"
# include "./../minilibx_macos/mlx.h"
# include <math.h>
# define CR mlx->params->c_r
# define CI mlx->params->c_i
# define ZR mlx->params->z_r
# define ZI mlx->params->z_i
# define Z mlx->params->zoom
# define FX mlx->params->framex
# define FY mlx->params->framey
# define XNEG mlx->params->x1
# define XPOS mlx->params->x2
# define YNEG mlx->params->y1
# define YPOS mlx->params->y2
# define COORDX mlx->params->x
# define COORDY mlx->params->y
# define BPP mlx->image->bpp
# define EY mlx->rose->ey
# define EX mlx->rose->ex
# define DX mlx->rose->dx
# define DY mlx->rose->dy
# define X_INCR mlx->rose->x_incr
# define Y_INCR mlx->rose->y_incr
# define RX mlx->rose->rx
# define RY mlx->rose->ry
# define W_WIDTH mlx->w_width
# define W_HEIGHT mlx->w_height
# define NAME mlx->str
# define I_MAX mlx->imax
# define BUTTON mlx->button
# define I_REF mlx->params->iref

typedef	struct			s_image {

	void				*image;
	char				*ptr;
	int					bpp;
	int					stride;
	int					endian;

}						t_image;

typedef struct			s_equ {

	double				tmp;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				zoom;
	int					iref;
	double				framex;
	double				framey;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	int					x;
	int					y;

}						t_equ;

typedef struct			s_algo {

	int					ey;
	int					ex;
	int					dx;
	int					dy;
	int					x_incr;
	int					y_incr;
	int					rx;
	int					ry;

}						t_algo;

typedef struct			s_mlx {

	void				*mlx;
	void				*win;
	t_image				*image;
	t_equ				*params;
	t_algo				*rose;
	int					w_width;
	int					w_height;
	int					imax;
	int					button;
	char				*str;

}						t_mlx;

void					mandel_maths(t_mlx *mlx);
void					image_set_pixel(t_mlx *mlx, int color);
void					*delete_image(t_mlx *mlx);
void					*new_image(t_mlx *mlx);
t_mlx					*initialize_win();
t_mlx					*mlx_free(t_mlx *mlx);
t_equ					*initialize();
void					julia_maths(t_mlx *mlx);
void					burningship_maths(t_mlx *mlx);
int						ft_get_color(int red, int green, int blue);
int						key_func(int keycode, t_mlx *mlx);
int						redraw_func(void *param);
int						mouse_func(int button, int x, int y, t_mlx *mlx);
void					re_calc_fractal(t_mlx *mlx, int x, int y);
int						mouse_movement(int x, int y, t_mlx *mlx);
void					init_burningship(t_mlx *mlx);
void					init_julia(t_mlx *mlx);
void					init_mandel(t_mlx *mlx);

#endif
