/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/26 10:03:19 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "philo_one.h"

t_data			g_data;

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1
		|| init_philosophers() == -1
		|| ((g_data.output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 1)) == SEM_FAILED))
	{
		if (g_data.output_sem && errno == EEXIST)
		{
			sem_unlink("output_sem");
			if (((g_data.output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 1)) == SEM_FAILED))
			{
				ph_error(PH_ERR_FATAL);
				destroy_philosophers();
				return (1);
			}
		}
		else
		{
			ph_error(PH_ERR_FATAL);
			destroy_philosophers();
			return (1);
		}
	}
	run_threads();
	join_threads();
	sem_close(g_data.output_sem);
	sem_unlink("output_sem");
	destroy_philosophers();
	return (0);
}
