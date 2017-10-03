/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:30:37 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/03 20:26:01 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void        image_set_pixel(t_mlx *mlx, int color)
{
	if (COORDX < 0 || COORDX >= W_WIDTH || COORDY < 0 || COORDY >= W_HEIGHT)
	{	
		printf("nope");
		return ;
	}
	*(int *)(mlx->image->ptr + ((COORDX + COORDY * W_WIDTH) * BPP)) = color;
}

void        *delete_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image->image);
			ft_memdel((void **)&mlx->image);
	}
	return (NULL);
}

void        *new_image(t_mlx *mlx)
{
	if ((mlx->image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((mlx->image->image =
				mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT)) == NULL)
		return (delete_image(mlx));
	mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
			            &mlx->image->stride, &mlx->image->endian);
	mlx->image->bpp /= 8;
	return (mlx->image);
}
