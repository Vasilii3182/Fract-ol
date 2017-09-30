/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:13:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/01 00:28:39 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*initialize_win()
{
	t_mlx *mlx;	

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if (((mlx->mlx = mlx_init()) == NULL) || (mlx->params = ft_memalloc(sizeof(t_equ))) == NULL)
		return (mlx_free(mlx));
	return (mlx);
}

t_mlx       *mlx_free(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->image != NULL)
		delete_image(mlx);
	ft_memdel((void **)&mlx);
	return (NULL);
}

/*void	*ft_create_window(int size_x, int size_y)
  {
  void *mlx;
  void *win;

  mlx = mlx_init();
  win = mlx_new_window(mlx, size_x, size_y, "fractol");

  }*/
