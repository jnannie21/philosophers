/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/21 07:53:29 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data			g_data;

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1
		|| init_philosophers() == -1
		|| (g_data.output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 1)) == SEM_FAILED
		|| (g_data.forks_sem = sem_open("forks_sem", O_CREAT | O_EXCL, S_IRWXU, g_data.number_of_philos)) == SEM_FAILED)
	{
		if (g_data.output_sem != SEM_FAILED)
		{
			sem_close(g_data.output_sem);
			sem_unlink("output_sem");
		}
		destroy_philosophers();
		sem_close(g_data.output_sem);
		sem_unlink("output_sem");
		sem_close(g_data.forks_sem);
		sem_unlink("forks_sem");
		return (1);
	}
	run_threads();
	join_threads();
	destroy_philosophers();
	sem_close(g_data.output_sem);
	sem_unlink("output_sem");
	sem_close(g_data.forks_sem);
	sem_unlink("forks_sem");
	return (0);
}
