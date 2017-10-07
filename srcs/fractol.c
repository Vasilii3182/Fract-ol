/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:51:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:47:30 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_search(char *str, char *charset)
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

void	activate_fractol(t_mlx *mlx)
{
	if (NAME[0] == 'M')
		init_mandel(mlx);
	if (NAME[0] == 'J')
		init_julia(mlx);
	if (NAME[0] == 'B')
		init_burningship(mlx);
}

int		main(int argc, char **argv)
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
	if ((mlx->win =
				mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "fractol")) == NULL)
		mlx_free(mlx);
	if ((mlx->image = new_image(mlx)) == NULL)
		mlx_free(mlx);
	NAME = ft_strdup(argv[1]);
	mlx_key_hook(mlx->win, key_func, mlx);
	mlx_mouse_hook(mlx->win, mouse_func, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_movement, mlx);
	activate_fractol(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
