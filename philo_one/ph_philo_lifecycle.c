/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/15 17:20:57 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_one.h"

static void	take_forks(t_philosopher *philo)
{
	if (philo->i % 2)
		pthread_mutex_lock(&philo->left_fork);
	else
		pthread_mutex_lock(&philo->right_fork);
	change_state(PH_FORK_TAKEN, &g_data.output_mutex, philo->i);
	if (!(philo->i % 2))
		pthread_mutex_lock(&philo->left_fork);
	else
		pthread_mutex_lock(&philo->right_fork);
	change_state(PH_FORK_TAKEN, &g_data.output_mutex, philo->i);
}

static void	put_forks_back(t_philosopher *philo)
{
	if (philo->i % 2)
		pthread_mutex_unlock(&philo->left_fork);
	else
		pthread_mutex_unlock(&philo->right_fork);
	if (!(philo->i % 2))
		pthread_mutex_unlock(&philo->left_fork);
	else
		pthread_mutex_unlock(&philo->right_fork);
}

void	*philo_lifecycle(void *philo)
{
	// struct timeval	tv;

	while (!g_data.some_philo_is_dead)
	{
		take_forks((t_philosopher *)philo);
		change_state(PH_EATING, &g_data.output_mutex, ((t_philosopher *)philo)->i);
		usleep(g_data.time_to_eat * 1000);

		// pthread_mutex_lock(&g_data.tv_mutex);
		// gettimeofday(&tv, NULL);
		// ((t_philosopher *)philo)->eat_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		pthread_mutex_lock(&((t_philosopher *)philo)->eat_time_mutex);
		((t_philosopher *)philo)->last_eat_time = ph_time();
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
		// pthread_mutex_unlock(&g_data.tv_mutex);

		put_forks_back((t_philosopher *)philo);
		change_state(PH_SLEEPING, &g_data.output_mutex, ((t_philosopher *)philo)->i);
		usleep(g_data.time_to_sleep * 1000);
		change_state(PH_THINKING, &g_data.output_mutex, ((t_philosopher *)philo)->i);
	}
	return (0);
}
