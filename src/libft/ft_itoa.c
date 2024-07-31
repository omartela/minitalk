/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:19:43 by omartela          #+#    #+#             */
/*   Updated: 2024/04/22 13:40:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static char	*number_to_string(char *ptr, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		*ptr = '-';
		i = i + count_digit(n) + 1;
	}
	else
		i = i + count_digit(n);
	ptr[i] = '\0';
	--i;
	if (n == 0)
	{
		ptr[i] = '0';
	}
	while (n > 0)
	{
		ptr[i] = n % 10 + '0';
		n = n / 10;
		--i;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(sizeof(char) * 12);
		if (!ptr)
			return (0);
		ft_strlcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	if (n < 0)
		ptr = malloc(sizeof(char) * count_digit(n) + 2);
	else
		ptr = malloc(sizeof(char) * count_digit(n) + 1);
	if (!ptr)
		return (0);
	number_to_string(ptr, n);
	return (ptr);
}
