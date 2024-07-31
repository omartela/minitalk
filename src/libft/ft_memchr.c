/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:50:25 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 12:55:27 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*temp_str;
	unsigned char	temp_c;

	temp_c = (unsigned char) c;
	temp_str = (unsigned char *) str;
	while (n > 0)
	{
		if (*temp_str == temp_c)
		{
			return (temp_str);
		}
		n = n - 1;
		temp_str = temp_str + 1;
	}
	return (0);
}
