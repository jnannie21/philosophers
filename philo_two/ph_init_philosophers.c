/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:42:52 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 14:30:41 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

static void		set_start_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static int		init_sems(int i)
{
	char			buf[PH_MAX_SEM_NAME_LEN];

	generate_sem_name("eat_time_sem", i, buf);
	if ((g_data.philos[i].eat_time_sem = ph_open_sem(buf, 1)) == SEM_FAILED)
		return (-1);
	return (0);
}

int				init_philosophers(void)
{
	int				i;
	int				rel_start_time;

	if (!(g_data.philos = ft_calloc(g_data.number_of_philos,
								sizeof(t_philosopher))))
		return (ph_error(PH_ERR_FATAL));
	g_data.forks_sem = ph_open_sem("forks_sem", g_data.number_of_philos);
	if (g_data.forks_sem == SEM_FAILED)
		return (-1);
	set_start_time();
	rel_start_time = ph_time();
	i = 0;
	while (i < g_data.number_of_philos)
	{
		g_data.philos[i].last_eat_time = rel_start_time;
		g_data.philos[i].i = i + 1;
		if (init_sems(i) == -1)
			return (ph_error(PH_ERR_FATAL));
		i++;
	}
	return (0);
}
