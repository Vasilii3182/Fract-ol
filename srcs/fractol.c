/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:51:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/03 22:45:46 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_burningship(t_mlx *mlx)
{
	XNEG = -3;
	XPOS = 2.5;
	YNEG = -2;
	YPOS = 3;
	I_MAX = 50;
	burningship_maths(mlx);
}

void	init_julia(t_mlx *mlx)
{
	XNEG = -2.1;
	XPOS = 0.6;
	YNEG = -1.2;
	YPOS = 1.2;
	I_MAX = 100;
	CI = 0.01;
	CR = 0.285;
	julia_maths(mlx);
}

void	init_mandel(t_mlx *mlx)
{
	XNEG = -2.1;
	XPOS = 0.6;
	YNEG = -1.2;
  	YPOS = 1.2;
	I_MAX = 50;
	mandel_maths(mlx);	
}

int	ft_search(char *str, char *charset)
{
	int i;
	
	i = 0;
	if (ft_strlen(str) != 1)
		return (0);
	while (charset[i] != '\0')
	{
		if (charset[i] == str[0])
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char	*charset;
	t_mlx	*mlx;
	
	charset = "BMJ";
	if ((mlx = initialize_win()) == NULL)
		return (-1);
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n");
		ft_putstr("[M]:Mandelbrot | [J]=Julia | [B]=Burning ship\n");
		return (0);
	}
	NAME = ft_strdup(argv[1]);
	W_WIDTH = 800;
	W_HEIGHT = 720;
	if ((mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "fractol")) == NULL)
		mlx_free(mlx);
	if ((mlx->image = new_image(mlx)) == NULL)
		mlx_free(mlx);
	if (argv[1][0] == 'M')
		init_mandel(mlx);
	if (argv[1][0] == 'J')
		init_julia(mlx);
	if (argv[1][0] == 'B')
		init_burningship(mlx);
	mlx_expose_hook(mlx->win, redraw_func, 0);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_mouse_hook(mlx->win, mouse_func, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_movement, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
