/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:04:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/24 10:53:05 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "philo_one.h"

static void		build_a_message(char *buf, int current_time, char *state,
					t_philosopher *philo)
{
	memset(buf, '\0', PH_BUFSIZE);
	ft_putnbr_to_buf(current_time, buf);
	ft_putstr_to_buf(" philosopher_", buf);
	ft_putnbr_to_buf(philo->i, buf);
	ft_putstr_to_buf(state, buf);
}

void			print_status(int current_time, char *state,
						t_philosopher *philo)
{
	static char	buf[PH_BUFSIZE];

	build_a_message(buf, current_time, state, philo);
	write(1, buf, ft_strlen(buf));
}
