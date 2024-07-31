/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:11:20 by omartela          #+#    #+#             */
/*   Updated: 2024/04/25 09:57:11 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_substr(char const *s, char c)
{
	size_t	count_words;

	count_words = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
			count_words += 1;
		while (*s && *s != c)
			++s;
	}
	return (count_words);
}

static void	free_memory(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**parse_strings(char **result, char const *s, char c)
{
	size_t			i;
	const char		*begin;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			begin = s;
			while (*s && *s != c)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - begin + 1));
			if (!result[i])
			{
				free_memory(result, i);
				return (NULL);
			}
			ft_strlcpy(result[i], begin, s - begin + 1);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!result)
		return (NULL);
	return (parse_strings(result, s, c));
}
