/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:51:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/09/30 23:50:35 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	
	charset = "MJ";
	if ((mlx = initialize_win()) == NULL)
		return (-1);
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if (argv[1][0] == 'J')
	{
		//Print_Julia;
		return (0);
	}
	if ((mlx->win = mlx_new_window(mlx->mlx, 700, 700, "fractol")) == NULL)
	{
		mlx_free(mlx);
		return (0);
	}
	if ((mlx->image = new_image(mlx)) == NULL)
	{
		mlx_free(mlx);
		return (0);
	}
	if (argv[1][0] == 'M')
	{
		mandel_maths(mlx);	
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
