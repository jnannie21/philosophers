/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 07:52:19 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/29 11:42:26 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int *g_pointer;

int		main(void)
{
	int		pid;
	int		*p;

	g_pointer = malloc(10);
	p = malloc(10);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		write(1, "child\n", 6);
		exit(0);
	}
	else
		write(1, "parent\n", 7);
	free(g_pointer);
	free(p);
	return (0);
}
