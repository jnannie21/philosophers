/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:04:32 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 15:06:34 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "philo_one.h"

static void		get_state_line(int state, char *buf)
{
	if (state == PH_FORK_TAKEN)
		ft_putstr_to_buf(PH_FORK_TAKEN_LINE, buf);
	else if (state == PH_EATING)
		ft_putstr_to_buf(PH_EATING_LINE, buf);
	else if (state == PH_SLEEPING)
		ft_putstr_to_buf(PH_SLEEPING_LINE, buf);
	else if (state == PH_THINKING)
		ft_putstr_to_buf(PH_THINKING_LINE, buf);
	else if (state == PH_DIED)
		ft_putstr_to_buf(PH_DIED_LINE, buf);
}

static void		build_a_message(char *buf, int current_time, int state,
							t_philosopher *philo)
{
	memset(buf, '\0', PH_BUFSIZE);
	ft_putnbr_to_buf(current_time, buf);
	ft_putstr_to_buf(" ", buf);
	ft_putnbr_to_buf(philo->i, buf);
	ft_putstr_to_buf(" ", buf);
	get_state_line(state, buf);
	ft_putstr_to_buf("\n", buf);
}

void			print_status(int current_time, int state,
						t_philosopher *philo)
{
	static char	buf[PH_BUFSIZE];

	build_a_message(buf, current_time, state, philo);
	write(1, buf, ft_strlen(buf));
}
