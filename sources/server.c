/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:31:43 by obritany          #+#    #+#             */
/*   Updated: 2021/09/09 14:31:45 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

void	handle_sig(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	symbol = 0b00000000;
	static unsigned char	bit = 0b10000000;
	(void) context;

	write(1, ".", 1);
	printf("%d", siginfo->si_pid);
	fflush(stdout);
	if (sig == SIGUSR1)
		symbol &= ~bit;
	if (sig == SIGUSR2)
		symbol |= bit;
	bit >>= 1;
	if (bit == 0)
	{
		write(1, &symbol, 1);
		bit = 0b10000000;
	}
	usleep(100);
	kill(siginfo->si_pid, sig);
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	act.sa_sigaction = &handle_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
