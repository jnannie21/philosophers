/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:45:41 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/21 06:54:58 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

void	*monitoring(void *philo)
{
	long			current_time;
	long			last_eat_time;

	while (1)
	{
		if (g_data.some_philo_is_dead)
			break ;
		current_time = ph_time();
		sem_wait(((t_philosopher *)philo)->eat_time_sem);
		last_eat_time = ((t_philosopher *)philo)->last_eat_time;
		if ((current_time - last_eat_time) > (g_data.time_to_die))
			change_state(PH_DIED, (t_philosopher *)philo);
		sem_post(((t_philosopher *)philo)->eat_time_sem);
		usleep(PH_MONITORING_DELAY);
	}
	return (0);
}
