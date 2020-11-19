/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/19 08:08:55 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data			g_data;

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1
		|| init_philosophers() == -1)
		return (1);
	pthread_mutex_init(&g_data.output_mutex, NULL);
	run_threads();
	join_threads();
	destroy_philosophers();
	pthread_mutex_destroy(&g_data.output_mutex);
	return (0);
}
