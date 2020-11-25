/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_change_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/25 03:48:34 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	check_if_all_philo_have_eaten(void)
{
	int		i;

	if (g_data.number_to_eat == -1)
		return ;
	i = 0;
	while (i < g_data.number_of_philos)
	{
		if (g_data.philos[i].count_eat_times < g_data.number_to_eat)
			break ;
		i++;
	}
	if (i == g_data.number_of_philos)
		g_data.some_philo_is_dead = 1;
}

void		change_state(char *state, t_philosopher *philo)
{
	int		current_time;

	pthread_mutex_lock(&g_data.output_mutex);
	if (g_data.some_philo_is_dead)
	{
		pthread_mutex_unlock(&g_data.output_mutex);
		return ;
	}
	current_time = ph_time();
	if (ft_strcmp(state, PH_EATING) == 0)
	{
		pthread_mutex_lock(&((t_philosopher *)philo)->eat_time_mutex);
		if (g_data.some_philo_is_dead)
		{
			pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
			pthread_mutex_unlock(&g_data.output_mutex);
			return ;
		}
		philo->last_eat_time = current_time;
		philo->count_eat_times++;
		check_if_all_philo_have_eaten();
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
	}
	print_status(current_time, state, philo);
	pthread_mutex_unlock(&g_data.output_mutex);
}
