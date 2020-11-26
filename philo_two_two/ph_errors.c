/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:09:04 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/26 07:09:11 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

int			ph_error(char *msg)
{
	write(2, PH_ERROR_INTRO, ft_strlen(PH_ERROR_INTRO));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (-1);
}
