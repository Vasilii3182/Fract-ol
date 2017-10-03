/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:33:21 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/03 17:23:26 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_get_color(int red, int green, int blue)
{
	int r;
	int g;
	int b;
	
	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;

	return (r << 16 | g << 8 | b);
}
