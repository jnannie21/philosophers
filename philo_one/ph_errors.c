/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:09:04 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/03 18:04:37 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			error_wrong_number_arguments(void)
{
	ft_putstr_fd("wrong number of arguments\n", 2);
	return (-1);
}

int			fatal_error(void)
{
	ft_putstr_fd("fatal error\n", 2);
	return (-1);
}
