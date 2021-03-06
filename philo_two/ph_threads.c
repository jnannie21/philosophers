/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:41:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 03:39:31 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_create(&g_data.philos[i].philo_thread, NULL,
					philo_lifecycle, g_data.philos + i);
		pthread_create(&g_data.philos[i].monitor_thread, NULL,
					monitoring, g_data.philos + i);
		i++;
	}
}

void	join_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_join(g_data.philos[i].philo_thread, NULL);
		pthread_join(g_data.philos[i].monitor_thread, NULL);
		i++;
	}
}
