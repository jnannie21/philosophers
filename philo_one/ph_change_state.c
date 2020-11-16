/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_change_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/16 07:02:36 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo_one.h"

void	change_state(char *state, int i)
{
	int				current_time;

	pthread_mutex_lock(&g_data.output_mutex);
	if (!g_data.some_philo_is_dead)
	{
		if (ft_strcmp(state, PH_DIED) == 0)
			g_data.some_philo_is_dead = 1;
		current_time = ph_time();
		ft_putnbr_fd(current_time, 1);
		ft_putstr_fd(" philosopher ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(state, 1);
	}
	pthread_mutex_unlock(&g_data.output_mutex);
	return ;
}
