/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_lifecycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/17 05:35:55 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

#include <stdio.h>

static void	take_forks(t_philosopher *philo)
{
	if (philo->i % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	change_state(PH_FORK_TAKEN, philo);
	if (!(philo->i % 2))
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	change_state(PH_FORK_TAKEN, philo);
}

static void	put_forks_back(t_philosopher *philo)
{
	if (philo->i % 2)
		pthread_mutex_unlock(philo->left_fork);
	else
		pthread_mutex_unlock(philo->right_fork);
	if (!(philo->i % 2))
		pthread_mutex_unlock(philo->left_fork);
	else
		pthread_mutex_unlock(philo->right_fork);
}

void	*philo_lifecycle(void *philo)
{
	while (1)
	{
		pthread_mutex_lock(&g_data.check_dead_philo_mutex);
		if (g_data.some_philo_is_dead)
		{
			pthread_mutex_unlock(&g_data.check_dead_philo_mutex);
			break ;
		}
		pthread_mutex_unlock(&g_data.check_dead_philo_mutex);
		take_forks((t_philosopher *)philo);
		change_state(PH_EATING, (t_philosopher *)philo);
		usleep(g_data.time_to_eat * 1000);
		put_forks_back((t_philosopher *)philo);
		change_state(PH_SLEEPING, (t_philosopher *)philo);
		usleep(g_data.time_to_sleep * 1000);
		change_state(PH_THINKING, (t_philosopher *)philo);
	}
	return (0);
}
