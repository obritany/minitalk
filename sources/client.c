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

void	handle_sig(int sig)
{
	(void) sig;
	// static unsigned char	symbol = 0b00000000;
	// static unsigned char	bit = 0b10000000;

	// if (sig != SIGUSR1 && sig != SIGUSR2)
	// 	return ;

	// write(1, ",", 1);
	// if (sig == SIGUSR1)
	// 	symbol &= ~bit;
	// if (sig == SIGUSR2)
	// 	symbol |= bit;
	// bit >>= 1;
	// if (bit == 0)
	// {
	// 	write(1, &symbol, 1);
	// 	bit = 0b10000000;
	// }
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
			write(1, ".", 1);
			if (str[i] & bit)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit >>= 1;
			pause();
		}
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
	signal(SIGUSR2, &handle_sig);
	i = 1;
	while (++i < argc)
	{
		send(argv[i], server_pid);
		if (argc - i > 1)
			send(" ", server_pid);
	}
	return (0);
}
