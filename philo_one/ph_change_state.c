/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_change_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 06:54:42 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	change_state(char *state, t_philosopher *philo)
{
	int				current_time;

	current_time = ph_time();
	pthread_mutex_lock(&g_data.check_dead_philo_mutex);
	if (g_data.some_philo_is_dead)
	{
		pthread_mutex_unlock(&g_data.check_dead_philo_mutex);
		return ;
	}
	if (ft_strcmp(state, PH_DIED) == 0)
	{
		g_data.some_philo_is_dead = 1;
	}
	else if (ft_strcmp(state, PH_EATING) == 0)
		philo->last_eat_time = current_time;
	pthread_mutex_unlock(&g_data.check_dead_philo_mutex);
	pthread_mutex_lock(&g_data.output_mutex);
	ft_putnbr_fd(current_time, 1);
	ft_putstr_fd(" philosopher_", 1);
	ft_putnbr_fd(philo->i, 1);
	ft_putstr_fd(state, 1);
	pthread_mutex_unlock(&g_data.output_mutex);
	return ;
}
