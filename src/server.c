/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:03:25 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/14 20:07:43 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	get_bits(int sig)
{
	static char	c = 0;
	static int	i = 7;

	if (sig == SIGUSR2)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		if (c == 0)
		{
			i = 7;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("\033[0;32mPID:\033[0m %d\n", getpid());
	signal(SIGUSR1, get_bits);
	signal(SIGUSR2, get_bits);
	while (1)
		pause();
	return (0);
}
