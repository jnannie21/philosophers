/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:41:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/28 16:10:06 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "philo.h"

static void	*number_to_eat_thread(void *arg)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		sem_wait(g_data.philo_full_sem);
		i++;
	}
	sem_wait(g_data.output_sem);
	kill(0, SIGKILL);
	return (arg);
}

void	run_threads(void)
{
	int		i;
	int		pid;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pid = fork();
		if (pid < 0)
			break ;
		else if (pid == 0)
		{
			pthread_create(&g_data.philos[i].philo_thread, NULL,
						philo_lifecycle, g_data.philos + i);
			pthread_create(&g_data.philos[i].monitor_thread, NULL,
						monitoring, g_data.philos + i);
			pthread_join(g_data.philos[i].philo_thread, NULL);
			pthread_join(g_data.philos[i].monitor_thread, NULL);
		}
		i++;
	}
	if (g_data.number_to_eat != -1)
	{
		pthread_create(&g_data.number_to_eat_thread, NULL,
					number_to_eat_thread, NULL);
		pthread_detach(g_data.number_to_eat_thread);
	}
	waitpid(-1, NULL, 0);
	// sem_wait(g_data.output_sem);
	// while (i < g_data.number_to_eat)
	// 	sem_post(g_data.philo_full_sem);
	kill(0, SIGKILL);
}
