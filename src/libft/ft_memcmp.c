/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:51:00 by omartela          #+#    #+#             */
/*   Updated: 2024/04/18 13:08:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*temp_str1;
	unsigned char	*temp_str2;

	temp_str1 = (unsigned char *) str1;
	temp_str2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (*temp_str1 != *temp_str2)
		{
			return (*temp_str1 - *temp_str2);
		}
		n = n - 1;
		temp_str1 = temp_str1 + 1;
		temp_str2 = temp_str2 + 1;
	}
	return (0);
}
