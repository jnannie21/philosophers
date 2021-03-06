/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_open_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 04:01:34 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/27 14:24:40 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "philo.h"

sem_t		*ph_open_sem(char *buf, int n)
{
	sem_t			*sem;

	if ((sem = sem_open(buf, O_CREAT | O_EXCL, S_IRWXU, n)) == SEM_FAILED)
	{
		if (errno == EEXIST)
		{
			sem_unlink(buf);
			sem = sem_open(buf, O_CREAT | O_EXCL, S_IRWXU, n);
		}
	}
	return (sem);
}
