/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:54:05 by omartela          #+#    #+#             */
/*   Updated: 2024/07/31 17:10:07 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

int	g_receiver = 0;

static void	sig_handler(int signum)
{
	static int	i = 0;

	g_receiver = 1;
	if (signum == SIGUSR2)
		++i;
	else if (signum == SIGUSR1)
		ft_putstr_fd("Bytes received so far \n", i / 8);
}

static int	char_to_bin(char c, int pid)
{
	int	itr;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (itr == 50)
			{
				ft_putstr_fd("No response from server \n", 1);
				exit(1);
			}
			itr += 1;
			usleep(100);
		}
		g_receiver = 0;
		bit_index -= 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					byte_index;
	int					pid;

	ft_memset(&sa, 0, sizeof(sa));
	byte_index = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = sig_handler;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			return (1);
		while (argv[2][byte_index])
			char_to_bin(argv[2][byte_index++], pid);
		char_to_bin('\0', pid);
	}
	return (0);
}
