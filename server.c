#include "minitalk.h"

void	handle_sigusr(int signal)
{
	static int	i = 0;
	static int	c = 0;

	c <<= 1;
	c += (signal == SIGUSR1);
	i++;
	if (i == 7)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting input from client...\n");
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		sleep(1);
	return (0);
}