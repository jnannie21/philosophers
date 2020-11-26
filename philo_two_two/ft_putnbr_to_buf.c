/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_to_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:33:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/24 06:14:49 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

static long		ft_pow10(int n)
{
	long		res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

static int		count_num(int n)
{
	int		num;

	num = 1;
	while (n / ft_pow10(num) != 0)
		num++;
	return (num);
}

void			ft_putnbr_to_buf(int n, char *buf)
{
	int		num;
	int		i;

	num = count_num(n);
	i = ft_strlen(buf);
	if (n >= 0)
		n *= (-1);
	else
		buf[i++] = '-';
	while (num--)
	{
		buf[i] = (-1) * ((n / ft_pow10(num)) % 10 - 48);
		i++;
	}
}
