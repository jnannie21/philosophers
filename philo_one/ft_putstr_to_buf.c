/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_to_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:15:36 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/24 06:32:02 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

void		ft_putstr_to_buf(char *s, char *buf)
{
	int		i;

	i = ft_strlen(buf);
	while (*s)
	{
		buf[i] = *s;
		s++;
		i++;
	}
}
