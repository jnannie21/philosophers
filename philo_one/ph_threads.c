/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:41:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/25 04:38:34 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	run_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_create(&g_data.philos[i].philo_thread, NULL,
					philo_lifecycle, g_data.philos + i);
		i++;
	}
	pthread_create(&g_data.monitor_thread, NULL,
				monitoring, NULL);
}

void	join_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_join(g_data.philos[i].philo_thread, NULL);
		i++;
	}
	pthread_join(g_data.monitor_thread, NULL);
}
