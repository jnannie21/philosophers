/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:52 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/21 07:48:22 by jnannie          ###   ########.fr       */
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

static int	init_sems(int i)
{
	g_data.philos[i].eattimesemname = ft_strjoin("eat_time_sem", ft_itoa(i));
	if (!g_data.philos[i].eattimesemname)
		return (-1);
	g_data.philos[i].eat_time_sem = sem_open(g_data.philos[i].eattimesemname, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (g_data.philos[i].eat_time_sem == SEM_FAILED)
		return (-1);
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
		if (init_sems(i) == -1)
			return (fatal_error());
		i++;
	}
	return (0);
}
