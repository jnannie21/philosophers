/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:16:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/20 07:21:49 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_one.h"

void	destroy_philosophers(void)
{
	int		i;

	i = 0;
	while (g_data.philos
			&& (i < g_data.number_of_philos)
			&& g_data.philos[i].left_fork)
	{
		pthread_mutex_destroy(g_data.philos[i].left_fork);
		free(g_data.philos[i].left_fork);
		pthread_mutex_destroy(&(g_data.philos)[i].eat_time_mutex);
		i++;
	}
	free(g_data.philos);
}
