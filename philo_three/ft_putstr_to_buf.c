/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_to_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:15:36 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 04:19:02 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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