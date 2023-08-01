/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:15:22 by onigiz            #+#    #+#             */
/*   Updated: 2023/02/28 14:15:30 by onigiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	coun;

	coun = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (temp == NULL)
		return (NULL);
	while (*s1)
	{
		temp[coun] = *s1;
		s1++;
		coun++;
	}
	temp[coun] = '\0';
	return (temp);
}
