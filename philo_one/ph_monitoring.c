/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:45:41 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/25 07:57:36 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		philo_is_died(t_philosopher *philo)
{
	g_data.some_philo_is_dead = 1;
	pthread_mutex_lock(&g_data.output_mutex);
	if (g_data.philos_have_eaten)
		return ;
	print_status(ph_time(), PH_DIED, philo);
	pthread_mutex_unlock(&g_data.output_mutex);
}

void			*monitoring(void *ret)
{
	int				current_time;
	int				last_eat_time;
	int				i;
	t_philosopher	*philo;

	while (1)
	{
		i = 0;
		current_time = ph_time();
		while (i < g_data.number_of_philos)
		{
			if (g_data.some_philo_is_dead)
				return (ret);
			philo = g_data.philos + i;
			pthread_mutex_lock(&philo->eat_time_mutex);
			last_eat_time = philo->last_eat_time;
			if ((current_time - last_eat_time) > (g_data.time_to_die))
				philo_is_died(philo);
			pthread_mutex_unlock(&philo->eat_time_mutex);
			i++;
		}
		ph_usleep(PH_MONITORING_DELAY);
	}
}
