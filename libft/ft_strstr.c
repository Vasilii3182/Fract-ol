/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:45:40 by ofranco           #+#    #+#             */
/*   Updated: 2016/11/26 20:00:42 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str1, char *str2)
{
	int		i;
	int		j;

	i = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			if (str2[j + 1] == '\0')
			{
				return (&str1[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
