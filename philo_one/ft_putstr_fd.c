/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:15:36 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/02 00:34:48 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

void		ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}