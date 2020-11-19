/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_change_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/19 23:31:15 by jnannie          ###   ########.fr       */
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

	current_time = ph_time();
	pthread_mutex_lock(&g_data.output_mutex);
	if (g_data.some_philo_is_dead)
	{
		pthread_mutex_unlock(&g_data.output_mutex);
		return ;
	}
	if (ft_strcmp(state, PH_DIED) == 0)
		g_data.some_philo_is_dead = 1;
	else if (ft_strcmp(state, PH_EATING) == 0)
	{
		philo->last_eat_time = current_time;
		philo->count_eat_times++;
		check_if_all_philo_have_eaten();
	}
	ft_putnbr_fd(current_time, 1);
	ft_putstr_fd(" philosopher_", 1);
	ft_putnbr_fd(philo->i, 1);
	ft_putstr_fd(state, 1);
	pthread_mutex_unlock(&g_data.output_mutex);
	return ;
}
