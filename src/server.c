/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:50:33 by omartela          #+#    #+#             */
/*   Updated: 2024/07/31 17:03:49 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

static void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c = *c << 1;
}

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i;
	static char	c = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	ft_memset(&sa, 0, sizeof(sa));
	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	free(pid);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		sleep(1);
	return (0);
}
