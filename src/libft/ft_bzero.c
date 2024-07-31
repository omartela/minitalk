/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:57 by omartela          #+#    #+#             */
/*   Updated: 2024/04/17 13:47:10 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*new;

	new = (unsigned char *)s;
	while (len > 0)
	{
		*new = 0;
		len = len - 1;
		new = new + 1;
	}
}
