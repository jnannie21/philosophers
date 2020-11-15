/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/15 18:45:23 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "philo_one.h"

t_data			g_data;

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
