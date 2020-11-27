/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_generate_sem_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:24:03 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 03:38:05 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philo.h"

void		generate_sem_name(char *base_name, int i, char *buf)
{
	memset(buf, '\0', PH_MAX_SEM_NAME_LEN);
	ft_putstr_to_buf(base_name, buf);
	ft_putnbr_to_buf(i, buf);
}
