/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:52 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/17 03:24:41 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "philo_one.h"

int	read_settings(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_wrong_number_arguments());
	g_data.number_of_philos = ft_atoi(argv[1]);
	g_data.time_to_die = ft_atoi(argv[2]);
	g_data.time_to_eat = ft_atoi(argv[3]);
	g_data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_data.number_to_eat = ft_atoi(argv[5]);
	return (0);
}

int	init_philosophers(void)
{
	int				i;
	struct timeval	tv;
	int				rel_start_time;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	rel_start_time = ph_time();
	if (!(g_data.philos = ft_calloc(g_data.number_of_philos, sizeof(t_philosopher))))
		return (fatal_error());
	i = 0;
	while (i < g_data.number_of_philos)
	{
		g_data.philos[i].last_eat_time = rel_start_time;
		g_data.philos[i].i = i + 1;
		if (!((g_data.philos)[i].left_fork = ft_calloc(1, sizeof(pthread_mutex_t))))
			return (fatal_error());
		pthread_mutex_init((g_data.philos)[i].left_fork, NULL);
		pthread_mutex_init(&(g_data.philos)[i].eat_time_mutex, NULL);
		if (i > 0)
			(g_data.philos)[i].right_fork = (g_data.philos)[i - 1].left_fork;
		i++;
	}
	(g_data.philos)[0].right_fork = (g_data.philos)[g_data.number_of_philos - 1].left_fork;
	return (0);
}
