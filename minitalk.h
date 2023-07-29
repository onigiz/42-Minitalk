/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:42:30 by onigiz            #+#    #+#             */
/*   Updated: 2023/07/26 18:42:35 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void ft_putchar(int c);
void ft_putstr(char *str);
void ft_putnbr (int nb);
int ft_ascii_to_int(char *str);
#endif