/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:16:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/26 08:26:20 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_one.h"

void	destroy_philosophers(void)
{
	int		i;
	char	buf[PH_MAX_SEM_NAME_LEN];

	i = 0;
	while (g_data.philos
			&& (i < g_data.number_of_philos))
	{
		if (g_data.philos[i].left_fork_sem && g_data.philos[i].left_fork_sem != SEM_FAILED)
		{
			sem_close(g_data.philos[i].left_fork_sem);
			generate_sem_name("fork_sem", i, buf);
			sem_unlink(buf);
		}
		if (g_data.philos[i].eat_time_sem && g_data.philos[i].eat_time_sem != SEM_FAILED)
		{
			sem_close(g_data.philos[i].eat_time_sem);
			generate_sem_name("eat_time_sem", i, buf);
			sem_unlink(buf);
		}
		i++;
	}
	free(g_data.philos);
}
