/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_lifecycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 14:14:58 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philosopher *philo)
{
	sem_wait(g_data.take_forks_sem);
	sem_wait(g_data.forks_sem);
	change_state(PH_FORK_TAKEN, philo);
	sem_wait(g_data.forks_sem);
	change_state(PH_FORK_TAKEN, philo);
	sem_post(g_data.take_forks_sem);
}

static void	put_forks_back(void)
{
	sem_post(g_data.forks_sem);
	sem_post(g_data.forks_sem);
}

void		*philo_lifecycle(void *philo)
{
	while (1)
	{
		if (g_data.some_philo_is_dead)
			break ;
		take_forks((t_philosopher *)philo);
		sem_wait(((t_philosopher *)philo)->eat_time_sem);
		change_state(PH_EATING, (t_philosopher *)philo);
		sem_post(((t_philosopher *)philo)->eat_time_sem);
		ph_usleep(g_data.time_to_eat);
		put_forks_back();
		change_state(PH_SLEEPING, (t_philosopher *)philo);
		ph_usleep(g_data.time_to_sleep);
		change_state(PH_THINKING, (t_philosopher *)philo);
	}
	return (0);
}
