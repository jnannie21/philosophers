/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:03:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/02 00:35:38 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stddef.h>

typedef struct		s_settings
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_settings;

void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);

int					error_wrong_number_arguments(void);
int					fatal_error(void);

#endif
