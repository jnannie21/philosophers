/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:52 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 21:08:40 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo_one.h"

static void	set_start_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static int	set_first_philo_right_fork(void)
{
	int				n_o_f;

	n_o_f = g_data.number_of_philos;
	if (n_o_f > 1)
		(g_data.philos)[0].right_fork = (g_data.philos)[n_o_f - 1].left_fork;
	else
	{
		if (!((g_data.philos)[0].right_fork = ft_calloc(1,
								sizeof(pthread_mutex_t))))
			return (fatal_error());
		pthread_mutex_init((g_data.philos)[0].right_fork, NULL);
	}
	return (0);
}

int			init_philosophers(void)
{
	int				i;
	int				rel_start_time;

	set_start_time();
	rel_start_time = ph_time();
	if (!(g_data.philos = ft_calloc(g_data.number_of_philos,
								sizeof(t_philosopher))))
		return (fatal_error());
	i = 0;
	while (i < g_data.number_of_philos)
	{
		g_data.philos[i].last_eat_time = rel_start_time;
		g_data.philos[i].i = i + 1;
		if (!((g_data.philos)[i].left_fork = ft_calloc(1,
								sizeof(pthread_mutex_t))))
			return (fatal_error());
		pthread_mutex_init((g_data.philos)[i].left_fork, NULL);
		pthread_mutex_init(&(g_data.philos)[i].eat_time_mutex, NULL);
		if (i > 0)
			(g_data.philos)[i].right_fork = (g_data.philos)[i - 1].left_fork;
		i++;
	}
	if (set_first_philo_right_fork() == -1)
		return (-1);
	return (0);
}
