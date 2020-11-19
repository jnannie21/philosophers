/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_read_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:15:44 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/19 05:43:04 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			read_settings(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (arg_is_error_not_numeric());
		i++;
	}
	if (argc < 5 || argc > 6)
		return (error_wrong_number_of_arguments());
	if (!(g_data.number_of_philos = ft_atoi(argv[1])))
		return (error_wrong_number_of_philosophers());
	g_data.time_to_die = ft_atoi(argv[2]);
	g_data.time_to_eat = ft_atoi(argv[3]);
	g_data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_data.number_to_eat = ft_atoi(argv[5]);
	else
		g_data.number_to_eat = -1;
	return (0);
}
