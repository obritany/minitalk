#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

#endif