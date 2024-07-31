/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:10 by omartela          #+#    #+#             */
/*   Updated: 2024/05/02 12:25:27 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	string_to_integer(const char *str, int sign)
{
	long long int	result;
	long long int	check;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		check = result * 10 + sign * (*str - '0');
		if (check / 10 != result && sign < 0)
			return (0);
		if (check / 10 != result && sign > 0)
			return (-1);
		result = check;
		++str;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	atoi;
	int	sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == '\n')
	{
		++str;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		++str;
	}
	atoi = string_to_integer(str, sign);
	return (atoi);
}
