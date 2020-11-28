/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:10:56 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 03:36:21 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define MAX_LONG_LENGTH 19
#define MAX_POS_LONG_VALUE 9223372036854775807UL

static char		*skip_insignificant_zeros(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

static int		digit_count(char *str)
{
	int		i;

	i = 0;
	while ((str[i] >= 48) && (str[i] <= 57))
		i++;
	return (i);
}

static char		*skip_whitespaces(char *str)
{
	while ((*str == '\t') || (*str == '\n') || (*str == '\r') ||
			(*str == '\v') || (*str == '\f') || (*str == ' '))
		str++;
	return (str);
}

int				ft_atoi(const char *nptr)
{
	char			*str;
	unsigned long	res;
	unsigned long	pow;
	int				sign;
	int				n;

	str = skip_whitespaces((char *)nptr);
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	str = skip_insignificant_zeros(str);
	res = 0;
	pow = 1;
	n = digit_count(str);
	while (n--)
	{
		if (res + (str[n] - 48) * pow > MAX_POS_LONG_VALUE)
			return ((sign == -1) ? 0 : -1);
		res = res + (str[n] - 48) * pow;
		pow *= 10;
	}
	return ((int)(sign * res));
}
