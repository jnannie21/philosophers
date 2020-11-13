/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:33:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/07 02:37:56 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

static void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

void			ft_putnbr_fd(int n, int fd)
{
	int		num;

	num = count_num(n);
	if (n >= 0)
		n *= (-1);
	else
		ft_putchar_fd('-', fd);
	while (num--)
		ft_putchar_fd((-1) * ((n / ft_pow10(num)) % 10 - 48), fd);
}
