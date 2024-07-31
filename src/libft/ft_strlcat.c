/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:31:32 by omartela          #+#    #+#             */
/*   Updated: 2024/01/18 16:34:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	j;
	size_t	amount_to_append;

	j = 0;
	dest_len = ft_strlen(dest);
	if (size == 0 || size <= dest_len)
		return (ft_strlen(src) + size);
	amount_to_append = size - dest_len - 1;
	while (src[j] != '\0' && j < amount_to_append)
	{
		dest[dest_len + j] = src[j];
		j = j + 1;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + ft_strlen(src));
}
