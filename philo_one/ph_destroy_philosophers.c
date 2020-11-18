/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:16:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 21:38:15 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_one.h"

void	destroy_philosophers(void)
{
	int				i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_mutex_destroy(g_data.philos[i].left_fork);
		free(g_data.philos[i].left_fork);
		pthread_mutex_destroy(&(g_data.philos)[i].eat_time_mutex);
		i++;
	}
	if (g_data.number_of_philos == 1)
	{
		pthread_mutex_destroy(g_data.philos[0].right_fork);
		free(g_data.philos[0].right_fork);
	}
	free(g_data.philos);
}
