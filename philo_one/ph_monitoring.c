/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:45:41 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/29 13:46:05 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

void	*monitoring(void *philo)
{
	int			current_time;
	int			last_eat_time;

	while (1)
	{
		if (g_data.some_philo_is_dead)
			break ;
		pthread_mutex_lock(&((t_philosopher *)philo)->eat_time_mutex);
		last_eat_time = ((t_philosopher *)philo)->last_eat_time;
		current_time = ph_time();
		if ((current_time - last_eat_time) >= (g_data.time_to_die))
			change_state(PH_DIED, (t_philosopher *)philo);
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
		usleep(PH_MONITORING_DELAY);
	}
	return (0);
}
