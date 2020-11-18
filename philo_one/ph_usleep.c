/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:31:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 02:00:10 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

void	ph_usleep(int usec)
{
	int	current_time;

	current_time = ph_time();
	while (current_time + usec > ph_time())
		usleep(PH_USLEEP_DELAY);
}
