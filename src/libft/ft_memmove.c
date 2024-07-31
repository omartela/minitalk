/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:57:07 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 18:40:16 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dest, source, len);
	else
	{
		dest += len - 1;
		source += len - 1;
		while (len > 0)
		{
			*dest-- = *source--;
			len = len - 1;
		}
	}
	return (dst);
}
