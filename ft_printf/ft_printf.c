/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:10:27 by onigiz            #+#    #+#             */
/*   Updated: 2023/03/27 13:10:37 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	kind(char a, va_list args)
{
	int	len;

	len = 0;
	if (a == 'd' || a == 'i')
		len += putnbr(va_arg(args, int ));
	else if (a == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (a == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (a == '%')
		len += ft_putchar('%');
	else if (a == 'u')
		len += unsigned_putnbr(va_arg(args, unsigned int));
	else if (a == 'p')
		len += pointer(va_arg(args, unsigned long), "0123456789abcdef");
	else if (a == 'x')
		len += hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (a == 'X')
		len += hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		sum;

	sum = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			sum += kind(s[i + 1], args);
			i++;
		}
		else
			sum += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (sum);
}