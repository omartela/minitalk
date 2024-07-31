/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:41:50 by omartela          #+#    #+#             */
/*   Updated: 2024/04/25 13:42:09 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_nodes;

	if (!lst)
		return (0);
	n_nodes = 0;
	while (lst != 0)
	{
		lst = lst->next;
		n_nodes = n_nodes + 1;
	}
	return (n_nodes);
}
