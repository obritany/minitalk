#include "minitalk.h"

void handle_sig(int sig)
{
	static int symbol = 0b00000000;
	static int bit = 0b10000000;

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
}

int main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, &handle_sig);
	signal(SIGUSR2, &handle_sig);
	while (1)
		pause();
	return (0);
}