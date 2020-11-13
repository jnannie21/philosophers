/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/13 06:29:25 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_one.h"

t_data			g_data;

static int	ph_time(void)
{
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((int)(current_time - g_data.start_time));
}

static int	read_settings(int argc, char **argv)
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

static int	init_philosophers(void)
{
	int				i;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (!(g_data.philos = ft_calloc(g_data.number_of_philos, sizeof(t_philosopher))))
		return (fatal_error());
	i = 0;
	while (i < g_data.number_of_philos)
	{
		g_data.philos[i].last_eat_time = g_data.start_time;
		g_data.philos[i].i = i + 1;
		pthread_mutex_init(&(g_data.philos)[i].left_fork, NULL);
		pthread_mutex_init(&(g_data.philos)[i].eat_time_mutex, NULL);
		if (i > 0)
			(g_data.philos)[i].right_fork = (g_data.philos)[i - 1].left_fork;
		i++;
	}
	(g_data.philos)[0].right_fork = (g_data.philos)[g_data.number_of_philos - 1].left_fork;
	return (0);
}

static void	change_state(char *state, pthread_mutex_t *output_mutex, int i)
{
	// struct timeval	tv;
	int				current_time;

	pthread_mutex_lock(output_mutex);
	if (!g_data.some_philo_is_dead)
	{
		if (ft_strcmp(state, PH_DIED) == 0)
			g_data.some_philo_is_dead = 1;
		// gettimeofday(&tv, NULL);
		current_time = ph_time();
		ft_putnbr_fd(current_time, 1);
		ft_putstr_fd(" philosopher ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(state, 1);
	}
	pthread_mutex_unlock(output_mutex);
	return ;
}

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

static void	*philo_lifecycle(void *philo)
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

static void	*monitoring(void *philo)
{
	// struct timeval	tv;
	long			current_time;
	long			last_eat_time;

	while (1)
	{
		pthread_mutex_lock(&((t_philosopher *)philo)->eat_time_mutex);
		last_eat_time = ((t_philosopher *)philo)->last_eat_time;
		pthread_mutex_unlock(&((t_philosopher *)philo)->eat_time_mutex);
		current_time = ph_time();
		if ((current_time - last_eat_time) > (g_data.time_to_die))
		{
			// ((t_philosopher *)philo)->is_dead = 1;
			pthread_mutex_lock(&g_data.check_dead_philo_mutex);
			if (!g_data.some_philo_is_dead)
			{
				change_state(PH_DIED, &g_data.output_mutex, ((t_philosopher *)philo)->i);
				// g_data.some_philo_is_dead = 1;
			}
			pthread_mutex_unlock(&g_data.check_dead_philo_mutex);
			break ;
		}
		usleep(MONITORING_DELAY);
	}
	return (0);
}

static void	run_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_create(&g_data.philos[i].philo_thread, NULL, philo_lifecycle, g_data.philos + i);
		pthread_create(&g_data.philos[i].monitor_thread, NULL, monitoring, g_data.philos + i);
		i++;
	}
}

static void	join_threads(void)
{
	int		i;

	i = 0;
	while (i < g_data.number_of_philos)
	{
		pthread_join(g_data.philos[i].philo_thread, NULL);
		pthread_join(g_data.philos[i].monitor_thread, NULL);
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1 ||
		init_philosophers() == -1)
		return (1);
	pthread_mutex_init(&g_data.output_mutex, NULL);
	pthread_mutex_init(&g_data.check_dead_philo_mutex, NULL);
	run_threads();
	join_threads();
	return (0);
}
