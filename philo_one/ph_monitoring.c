/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:45:41 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/24 10:53:25 by jnannie          ###   ########.fr       */
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
		current_time = ph_time();
		last_eat_time = ((t_philosopher *)philo)->last_eat_time;
		if ((current_time - last_eat_time) > (g_data.time_to_die))
		{
			pthread_mutex_lock(&g_data.dead_philo_mutex);
			if (g_data.some_philo_is_dead)
				break ;
			g_data.some_philo_is_dead = 1;
			pthread_mutex_lock(&g_data.output_mutex);
			print_status(current_time, PH_DIED, philo);
			pthread_mutex_unlock(&g_data.output_mutex);
			pthread_mutex_unlock(&g_data.dead_philo_mutex);
		}
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
		usleep(PH_MONITORING_DELAY);
	}
	return (0);
}
