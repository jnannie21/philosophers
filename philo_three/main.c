/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/28 16:03:07 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

t_data			g_data;

static void	destroy_global_sems(void)
{
	sem_close(g_data.output_sem);
	sem_unlink("output_sem");
	sem_close(g_data.take_forks_sem);
	sem_unlink("take_forks_sem");
	sem_close(g_data.philo_full_sem);
	sem_unlink("philo_full_sem");
}

static int	init_global_sems(void)
{
	if ((g_data.output_sem = ph_open_sem("output_sem", 1))
			== SEM_FAILED
		|| (g_data.take_forks_sem = ph_open_sem("take_forks_sem", 1))
			== SEM_FAILED
		|| (g_data.philo_full_sem = ph_open_sem("philo_full_sem", 0))
			== SEM_FAILED)
	{
		destroy_global_sems();
		// if (g_data.take_forks_sem == SEM_FAILED)
		// {
		// 	sem_close(g_data.output_sem);
		// 	sem_unlink("output_sem");
		// }
		destroy_philosophers();
		return (ph_error(PH_ERR_FATAL));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1
		|| init_philosophers() == -1
		|| init_global_sems() == -1)
	{
		destroy_philosophers();
		return (1);
	}
	run_threads();
	destroy_global_sems();
	destroy_philosophers();
	printf("here\n");
	return (0);
}
