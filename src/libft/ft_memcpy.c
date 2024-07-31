/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:36 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 17:34:04 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (len == 0 || dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (len > 0)
	{
		*dest = *source;
		dest = dest + 1;
		source = source + 1;
		len = len - 1;
	}
	return (dst);
}
