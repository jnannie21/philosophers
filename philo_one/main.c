/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/04 01:08:24 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "philo_one.h"

#include <stdio.h>

static int	read_settings(t_data *data, int argc,
									char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_wrong_number_arguments());
	memset(data, '\0', sizeof(*data));
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_to_eat = ft_atoi(argv[5]);
	return (0);
}

static int	init_philosophers(t_philosopher **philos, int number_of_philos)
{
	int		i;

	if (!(*philos = ft_calloc(number_of_philos, sizeof(t_philosopher))))
		return (fatal_error());
	i = 0;
	while (i < number_of_philos)
	{
		if (i > 0)
			(*philos)[i].right_fork = (*philos)[i - 1].left_fork;
		pthread_mutex_init((*philos)[i].left_fork, NULL);
		i++;
	}
	(*philos)[0].right_fork = (*philos)[number_of_philos - 1].left_fork;
	return (0);
}

static void	change_state(t_philosopher *philo, int state)
{
	return ;
}

static void	*philo_lifecycle(void *data, t_philosopher *philo)
{
	pthread_mutex_lock(((t_philosopher *)philo)->right_fork);
	change_state(philo, PH_TOOK_RIGHT_FORK);
	pthread_mutex_lock(((t_philosopher *)philo)->left_fork);
	change_state(philo, PH_TOOK_LEFT_FORK);
	change_state(philo, PH_EATING);
	usleep(((t_data *)data)->time_to_eat);
}

static int	run_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_lifecycle,
						data);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_data			data;
	// t_philosopher	*philos;
	char			*str;

	if (read_settings(&data, argc, argv) == -1 ||
		init_philosophers(&data.philos, data.number_of_philos) == -1)
		return (1);
	run_threads(&data);
	// create threads with eating, sleeping and thinking
	// create one companion statuses monitoring thread
	// profit
	return (0);
}
