/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:16:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/29 12:11:29 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static void	destroy_global_sems(void)
{
	if (g_data.output_sem && (g_data.output_sem != SEM_FAILED))
	{
		sem_close(g_data.output_sem);
		sem_unlink("output_sem");
	}
	if (g_data.take_forks_sem && (g_data.take_forks_sem != SEM_FAILED))
	{
		sem_close(g_data.take_forks_sem);
		sem_unlink("take_forks_sem");
	}
	if (g_data.forks_sem && (g_data.forks_sem != SEM_FAILED))
	{
		sem_close(g_data.forks_sem);
		sem_unlink("forks_sem");
	}
}

void		destroy_philosophers(void)
{
	int		i;
	char	buf[PH_MAX_SEM_NAME_LEN];

	destroy_global_sems();
	i = 0;
	while (g_data.philos
			&& (i < g_data.number_of_philos))
	{
		if (g_data.philos[i].eat_time_sem
			&& g_data.philos[i].eat_time_sem != SEM_FAILED)
		{
			sem_close(g_data.philos[i].eat_time_sem);
			generate_sem_name("eat_time_sem", i, buf);
			sem_unlink(buf);
		}
		i++;
	}
	free(g_data.philos);
}
