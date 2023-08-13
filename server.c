/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:30:56 by onigiz            #+#    #+#             */
/*   Updated: 2023/08/14 02:30:58 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	usr_signal(int signal)
{
	static int	i = 0;
	static int	c = 0;

	c <<= 1;
	c += (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting for client activity...\n");
	signal(SIGUSR1, usr_signal);
	signal(SIGUSR2, usr_signal);
	while (1)
		sleep(1);
	return (0);
}
