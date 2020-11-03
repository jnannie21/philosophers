/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:03:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/04 00:50:36 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stddef.h>

# define PH_TOOK_RIGHT_FORK 1
# define PH_TOOK_LEFT_FORK 2
# define PH_EATING 3
# define PH_SLEEPING 4
# define PH_THINKING 5

typedef struct		s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_to_eat;
	t_philosopher	*philos;
}					t_data;

typedef struct		s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	int				state;
}					t_philosopher;

void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);

int					error_wrong_number_arguments(void);
int					fatal_error(void);

#endif
