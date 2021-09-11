/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:31:21 by obritany          #+#    #+#             */
/*   Updated: 2021/09/09 14:31:23 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_sig = 0;

void	handle_sig(int sig)
{
	g_sig = sig;
}

void	send(char *str, pid_t pid)
{
	unsigned char	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0b10000000;
		while (bit > 0)
		{
			if (str[i] & bit)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(10000);
			usleep(25);
			if (!g_sig)
				continue;
			g_sig = 0;
			bit >>= 1;
		}
		write(1, ".", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc < 3)
	{
		ft_putstr_fd("Error: Not enough arguments\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
	{
		ft_putstr_fd("Error: Wrong PID\n", 2);
		return (2);
	}
	signal(SIGUSR1, &handle_sig);
	i = 1;
	while (++i < argc)
	{
		send(argv[i], server_pid);
		if (argc - i > 1)
			send(" ", server_pid);
	}
	ft_putstr_fd("\nMessage delivered!\n", 1);
	return (0);
}
