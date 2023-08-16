/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 01:30:07 by onigiz            #+#    #+#             */
/*   Updated: 2023/08/15 01:37:19 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	usr_signal(int signal)//Signal fonksiyonu nasıl çalışıyor?
{
	static int	i;//Bit seviyesinde işlem olduğundan yer tayini ve update için static olması gerekli
	static int	c;

	if (i < 8)
	{
		c <<= 1;
		c += (signal == SIGUSR1);//Eşitse 1, değilse 0 eklemesi
		i++;
		if (i == 8)//Aslında bu noktada mantıken unicode desteğini sağlayamaması gerekiyor ancak işletim sist. / terminal'den dolayı unicode karakter de bastırıyor?
		{
			ft_printf("%c", c);
			c = 0;//0'a eşitleniyorlar çünkü artık yeni karaktere geçilecek
			i = 0;
		}
	}
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting for client activity...\n");
	signal(SIGUSR1, usr_signal);
	signal(SIGUSR2, usr_signal);
	while (1)
		sleep (1);
	return (0);
}
