/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:59:23 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/15 17:19:44 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	push_byte(int c, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	receiver(int sig)
{
	static int	cont = 0;

	if (sig == SIGUSR2)
		cont++;
	else
		exit(ft_printf("\033[0;32m%d bytes received\n\033[0m", cont));
}

int	main(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (ft_putstr_fd("\033[0;31mParameters error\n\033[0m", 2), -1);
	signal(SIGUSR1, receiver);
	signal(SIGUSR2, receiver);
	while (i <= ft_strlen(argv[2]))
	{
		push_byte(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
	return (0);
}
