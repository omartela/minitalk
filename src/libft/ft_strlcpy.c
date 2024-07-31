/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:39:17 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 14:05:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while (counter < dstsize - 1 && *(src + counter) != '\0')
		{
			*(dst + counter) = *(src + counter);
			counter++;
		}
		*(dst + counter) = '\0';
	}
	return (ft_strlen(src));
}
