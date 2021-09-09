/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:31:52 by obritany          #+#    #+#             */
/*   Updated: 2021/09/09 14:31:53 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (c);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_atoi(const char *str)
{
	unsigned long long	pre_max;
	unsigned long long	rslt;
	int					sign;
	int					i;

	pre_max = 922337203685477580;
	rslt = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1)
			if (rslt > pre_max || (rslt == pre_max && str[i] > '7'))
				return (-1);
		if (sign == -1)
			if (rslt > pre_max || (rslt == pre_max && str[i] > '8'))
				return (0);
		rslt = (rslt * 10) + (str[i++] - '0');
	}
	return (rslt * sign);
}
