/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:09:35 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/14 18:08:46 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	push_bits(char c, int server_pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i & 1);
		if (bit == 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	size_t	i;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (ft_putstr_fd("\033[0;31mParameters error\n\033[0m", 2), -1);
	message = argv[2];
	i = 0;
	while (i <= ft_strlen(message))
	{
		push_bits(message[i], ft_atoi(argv[1]));
		i++;
	}
	return (0);
}
