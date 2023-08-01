/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:10:49 by onigiz            #+#    #+#             */
/*   Updated: 2023/02/18 21:10:51 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	coun;

	coun = 0;
	while (s[coun])
		coun++;
	while (coun >= 0)
	{
		if (s[coun] == (char)c)
			return ((char *)(s + coun));
		coun--;
	}
	return (NULL);
}
