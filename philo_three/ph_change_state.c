/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_change_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/28 14:29:04 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

// static void	check_if_all_philo_have_eaten(void)
// {
// 	int		i;

// 	i = 0;
// 	while (i < g_data.number_of_philos)
// 	{
// 		if (g_data.philos[i].count_eat_times < g_data.number_to_eat)
// 			break ;
// 		i++;
// 	}
// 	if (i == g_data.number_of_philos)
// 		exit(0);
// }

void		change_state(char *state, t_philosopher *philo)
{
	int		current_time;

	sem_wait(g_data.output_sem);
	current_time = ph_time();
	print_status(current_time, state, philo);
	if (ft_strcmp(state, PH_EATING) == 0)
	{
		philo->last_eat_time = current_time;
		if (g_data.number_to_eat != -1)
		{
			philo->count_eat_times++;
			if (philo->count_eat_times == g_data.number_to_eat)
				sem_post(g_data.philo_full_sem);
			// check_if_all_philo_have_eaten();
		}
	}
	else if (ft_strcmp(state, PH_DIED) == 0)
		exit(0);
	sem_post(g_data.output_sem);
}
