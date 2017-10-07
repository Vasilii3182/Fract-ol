/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:13:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/07 13:47:22 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*initialize_win(void)
{
	t_mlx *mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if (((mlx->mlx = mlx_init()) == NULL)
			|| (mlx->params = ft_memalloc(sizeof(t_equ))) == NULL
			|| (mlx->rose = ft_memalloc(sizeof(t_algo))) == NULL)
		return (mlx_free(mlx));
	W_WIDTH = 800;
	W_HEIGHT = 720;
	return (mlx);
}

t_mlx	*mlx_free(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image != NULL)
		delete_image(mlx);
	ft_memdel((void **)&mlx);
	exit(0);
	return (NULL);
}
