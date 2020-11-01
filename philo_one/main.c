/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/02 01:07:49 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "philo_one.h"

static int	read_settings(t_settings **settings, int argc, char **argv)
{
	if (!(*settings = ft_calloc(1, sizeof(t_settings))))
		return (fatal_error());
	if (argc < 5 || argc > 6)
	{
		free(*settings);
		*settings = 0;
		return (error_wrong_number_arguments());
	}
	(*settings)->number_of_philosophers = ft_atoi(argv[1]);
	(*settings)->time_to_die = ft_atoi(argv[2]);
	(*settings)->time_to_die = ft_atoi(argv[3]);
	(*settings)->time_to_die = ft_atoi(argv[4]);
	if (argc == 6)
		(*settings)->time_to_die = ft_atoi(argv[5]);
	return (0);
}

int			main(int argc, char **argv)
{
	t_settings	*settings;

	if (read_settings(&settings ,argc, argv) == -1)
		return (1);
	return (argc && argv);
}


	// read args with settings;
	// create philosophers
	// init forks by number of philosofers and save them in philo structure;
	// create threads in while loop by number of philosophers;
