/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:40:21 by onigiz            #+#    #+#             */
/*   Updated: 2023/07/26 18:40:25 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        ft_putchar(str[i++]);    
}

void    ft_putnbr(int nb)
{
    if (nb >= 0 && nb <=9)
        ft_putchar(nb + 48);
    else if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + 48);
    }
}


int ft_ascii_to_int(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] != '\0')
    {
        num *= 10;
        num += str[i] - 48;
        i++;
    }
    return (num);
    
}