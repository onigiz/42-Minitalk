/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:30:42 by onigiz            #+#    #+#             */
/*   Updated: 2023/08/15 01:44:10 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_char;
//Global değişken kullanmak yerine send char 
//fonksiyonuna "char ch" türünde bir parametre
//ekleyerek de işlem yapabiliriz.

void	send_bit(int pid)
{
	if ((128 & g_char) == 128)
		kill(pid, SIGUSR1);//pid processine SIGUSR1 sinyali yolluyor, bit = 1
	else
		kill(pid, SIGUSR2);//pid processine SIGUSR2 sinyali yolluyor, bit = 0
	usleep(50);//sinyal aktarımında karışıklığa önlem
}

void	send_char(int pid)
{
	int	i;

	i = 0;
	while (i < 8)//Bit seviyesinde kontrol yapılıyor
	{
		send_bit(pid);
		g_char <<= 1;
		i++;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		g_char = str[i];
		send_char(pid);
		i++;
	}
	g_char = '\n';
	send_char(pid);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		g_char = 0;
		send_message(argv[2], pid);
	}
	else
	{
		ft_printf("Use valid format: ./client <PID> <Message>");
		return (1);
	}
	return (0);
}
