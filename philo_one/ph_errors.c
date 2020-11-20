/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:09:04 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/20 05:47:11 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			error_wrong_number_of_arguments(void)
{
	ft_putstr_fd("wrong number of arguments\n", 2);
	return (-1);
}

int			error_wrong_number_of_philosophers(void)
{
	ft_putstr_fd("wrong number of philosophers(must be > 1)\n", 2);
	return (-1);
}

int			arg_is_error_not_numeric(void)
{
	ft_putstr_fd("all arguments must be numeric\n", 2);
	return (-1);
}

int			fatal_error(void)
{
	ft_putstr_fd("fatal error\n", 2);
	return (-1);
}
