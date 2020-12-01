/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:41:17 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/01 15:42:53 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "philo.h"

static void		*number_to_eat_thread(void *pid)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		if (i > 0)
			sem_post(g_data.output_sem);
		sem_wait(g_data.philo_full_sem);
		i++;
	}
	kill(*(int *)pid, SIGKILL);
	return (0);
}

static void		ph_kill_all_childs(int dead_child)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		if (g_data.philo_ids[i] && (g_data.philo_ids[i] != dead_child))
			kill(g_data.philo_ids[i], SIGKILL);
		i++;
	}
}

static void		child_process(int i)
{
	pthread_create(&g_data.philos[i].philo_thread, NULL,
				philo_lifecycle, g_data.philos + i);
	pthread_create(&g_data.philos[i].monitor_thread, NULL,
				monitoring, g_data.philos + i);
	pthread_join(g_data.philos[i].philo_thread, NULL);
	pthread_join(g_data.philos[i].monitor_thread, NULL);
}

static int		ph_fork_error(void)
{
	ph_kill_all_childs(0);
	return (ph_error(PH_ERR_FATAL));
}

int				run_threads(void)
{
	int		i;
	int		pid;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pid = fork();
		if (pid < 0)
			return (ph_fork_error());
		else if (pid == 0)
			child_process(i);
		g_data.philo_ids[i] = pid;
		i++;
	}
	if (g_data.number_to_eat != -1)
	{
		pthread_create(&g_data.number_to_eat_thread, NULL,
					number_to_eat_thread, &pid);
		pthread_detach(g_data.number_to_eat_thread);
	}
	pid = waitpid(-1, NULL, 0);
	ph_kill_all_childs(pid);
	return (0);
}
