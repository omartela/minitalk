/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:30:29 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 10:48:21 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int x, size_t len)
{
	unsigned char			*new;

	new = (unsigned char *)b;
	while (len > 0)
	{
		*new = (unsigned char) x;
		len = len - 1;
		new = new + 1;
	}
	return (b);
}
