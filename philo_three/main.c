/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:28:48 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/01 15:23:12 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data			g_data;

int			main(int argc, char **argv)
{
	if (read_settings(argc, argv) == -1
		|| init_philosophers() == -1
		|| run_threads() == -1)
	{
		destroy_philosophers();
		return (1);
	}
	destroy_philosophers();
	return (0);
}
