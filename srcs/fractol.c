/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:51:39 by ofranco           #+#    #+#             */
/*   Updated: 2017/09/30 16:25:11 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_search(char *str, char *charset)
{
	int i;
	
	if (ft_strlen(str) != 1)
		return (0);
	while (charset[i] != \0)
	{
		if (charset[i] == str[0])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char *charset;
	
	charset = "MJ"
	if (argc != 2 || ft_search(argv[1], charset) == 0)
	{
		ft_putstr("Usage : ./fractol [fractal]\n[M]:Mandelbrot | [J]:Julia |");
		return (0);
	}
	if (argv[1] == "J")
	{
		Print_Julia;
		return (0)
	}
	if (argv[1] == "M")
	{
		Print_Mandelbrot;
		return (0);
	}
	ft_putstr("Error\n");
	return (0);
}
