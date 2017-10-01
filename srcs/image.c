/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:30:37 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 17:31:05 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void        image_set_pixel(t_mlx *mlx)
{
	if (COORDX < 0 || COORDX >= 700 || COORDY < 0 || COORDY >= 700)
	{	
		printf("nope jecris pas : COORDX =%d, COORDY =%d\n", COORDX, COORDY);
		return ;
	}
	printf("j'imprime aux coordonnees : COORDX=%d COORDY=%d\n\n", COORDX, COORDY);
	*(int *)(mlx->image->ptr + ((COORDX + COORDY * 700) * BPP)) = 0xFFFFFF;
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
				mlx_new_image(mlx->mlx, 700, 700)) == NULL)
		return (delete_image(mlx));
	mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
			            &mlx->image->stride, &mlx->image->endian);
	mlx->image->bpp /= 8;
	return (mlx->image);
}
