/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:03:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/19 08:08:50 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stddef.h>

# define PH_FORK_TAKEN " has taken a fork\n"
# define PH_EATING " is eating\n"
# define PH_SLEEPING " is sleeping\n"
# define PH_THINKING " is thinking\n"
# define PH_DIED " died\n"
# define PH_MONITORING_DELAY 1000
# define PH_USLEEP_DELAY 100

typedef struct		s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	eat_time_mutex;
	pthread_t		philo_thread;
	pthread_t		monitor_thread;
	int				state;
	int				i;
	int				last_eat_time;
	int				is_dead;
	int				count_eat_times;
}					t_philosopher;

typedef struct		s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_to_eat;
	t_philosopher	*philos;
	pthread_mutex_t	output_mutex;
	int				some_philo_is_dead;
	long			start_time;
}					t_data;

extern t_data		g_data;

void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(char *s1, char *s2);
int					ft_isdigit(int c);

int					error_wrong_number_of_arguments(void);
int					error_wrong_number_of_philosophers(void);
int					arg_is_error_not_numeric(void);
int					fatal_error(void);

void				*philo_lifecycle(void *philo);
void				*monitoring(void *philo);
void				change_state(char *state, t_philosopher *philo);
int					ph_time(void);
void				run_threads(void);
void				join_threads(void);
int					read_settings(int argc, char **argv);
int					init_philosophers(void);
void				destroy_philosophers(void);
void				ph_usleep(int msec);

#endif
