/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:16:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/21 07:40:37 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_one.h"

void	destroy_philosophers(void)
{
	int		i;

	i = 0;
	while (g_data.philos
			&& (i < g_data.number_of_philos))
	{
		sem_close((g_data.philos)[i].eat_time_sem);
		sem_unlink(g_data.philos[i].eattimesemname);
		free(g_data.philos[i].eattimesemname);
		i++;
	}
	free(g_data.philos);
}
