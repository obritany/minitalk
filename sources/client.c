#include "minitalk.h"

static char	*ft_get_argv(int argc, char **argv)
{
	char	*output;
	char	*temp1;
	char	*temp2;
	int		i;

	i = 2;
	if (argc == 3)
		output = ft_strdup(argv[2]);
	else
	{
		output = ft_strdup(argv[2]);
		while (++i < argc)
		{
			temp1 = ft_strjoin(output, " ");
			temp2 = ft_strjoin(temp1, argv[i]);
			free(output);
			output = ft_strdup(temp2);
			free(temp1);
			free(temp2);
		}
	}
	return (output);
}

static void	ft_sender(int ppid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 128;
		while (j > 0)
		{
			usleep (50);
			if (message[i] & j)
				kill(ppid, SIGUSR1);
			else
				kill(ppid, SIGUSR2);
			j /= 2;
		}
		usleep (50);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		ppid;
	char	*message;

	if (argc < 3)
	{
		ft_putendl_fd("Error\nNotenough arguements", 2);
		exit(1);
	}
	ppid = ft_atoi(argv[1]);
	message = ft_get_argv(argc, argv);
	ft_sender(ppid, message);
	free(message);
	return (0);
}
