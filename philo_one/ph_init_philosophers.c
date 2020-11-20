/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:52 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/20 07:21:18 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "philo_one.h"

static void	set_start_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static int	init_mutexes(int i)
{
	if (!((g_data.philos)[i].left_fork = ft_calloc(1,
							sizeof(pthread_mutex_t))))
		return (-1);
	if (pthread_mutex_init((g_data.philos)[i].left_fork, NULL))
	{
		free((g_data.philos)[i].left_fork);
		(g_data.philos)[i].left_fork = 0;
		return (-1);
	}
	if (pthread_mutex_init(&(g_data.philos)[i].eat_time_mutex, NULL))
	{
		pthread_mutex_destroy(g_data.philos[i].left_fork);
		free((g_data.philos)[i].left_fork);
		(g_data.philos)[i].left_fork = 0;
		return (-1);
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
		if (init_mutexes(i) == -1)
			return (fatal_error());
		if (i > 0)
			(g_data.philos)[i].right_fork = (g_data.philos)[i - 1].left_fork;
		i++;
	}
	(g_data.philos)[0].right_fork =
		(g_data.philos)[g_data.number_of_philos - 1].left_fork;
	return (0);
}
