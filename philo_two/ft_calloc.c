/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:43:00 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/18 07:33:46 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo_one.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mem_size;

	mem_size = nmemb * size;
	mem = malloc(mem_size);
	if (mem == 0)
		return (0);
	memset(mem, '\0', mem_size);
	return (mem);
}
