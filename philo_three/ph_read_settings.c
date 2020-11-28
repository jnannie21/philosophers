/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_read_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:15:44 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/28 14:24:01 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (ph_error(PH_ERR_NOT_NUMERIC_ARG));
		i++;
	}
	if (argc < 5 || argc > 6)
		return (ph_error(PH_ERR_WRONG_NUMBER_ARG));
	if ((g_data.number_of_philos = ft_atoi(argv[1])) < 2)
		return (ph_error(PH_ERR_WRONG_NUMBER_PHILO));
	g_data.time_to_die = ft_atoi(argv[2]);
	g_data.time_to_eat = ft_atoi(argv[3]);
	g_data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		g_data.number_to_eat = ft_atoi(argv[5]);
	else
		g_data.number_to_eat = -1;
	if (g_data.number_to_eat == 0)
		return (ph_error(PH_ERR_WRONG_NUMBER_EAT));
	return (0);
}
