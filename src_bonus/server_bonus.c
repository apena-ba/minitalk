/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:22:52 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/15 17:21:28 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	get_bits(int sig, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	i = 7;
	static int	pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		if (c == '\0')
		{
			kill(pid, SIGUSR1);
			i = 7;
			pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		kill(pid, SIGUSR2);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	data;

	ft_printf("\033[0;32mPID:\033[0m %d\n", getpid());
	data.sa_sigaction = get_bits;
	data.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &data, NULL);
	sigaction(SIGUSR2, &data, NULL);
	while (1)
		pause();
}
