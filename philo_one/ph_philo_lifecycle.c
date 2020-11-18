/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_lifecycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 07:35:03 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void		*philo_lifecycle(void *philo)
{
	while (1)
	{
		if (g_data.some_philo_is_dead)
			break ;
		take_forks((t_philosopher *)philo);
		pthread_mutex_lock(&((t_philosopher *)philo)->eat_time_mutex);
		change_state(PH_EATING, (t_philosopher *)philo);
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
		ph_usleep(g_data.time_to_eat);
		put_forks_back((t_philosopher *)philo);
		change_state(PH_SLEEPING, (t_philosopher *)philo);
		ph_usleep(g_data.time_to_sleep);
		change_state(PH_THINKING, (t_philosopher *)philo);
	}
	return (0);
}
