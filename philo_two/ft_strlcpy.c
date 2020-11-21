/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:49:18 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/21 07:49:51 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1))
		{
			if ((dst[i] = src[i]) == '\0')
				return (i);
			i++;
		}
		dst[size - 1] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
