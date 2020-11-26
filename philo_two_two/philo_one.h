/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:03:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/11/26 08:24:37 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <semaphore.h>
# include <stddef.h>

# define PH_FORK_TAKEN "has taken a fork"
# define PH_EATING "is eating"
# define PH_SLEEPING "is sleeping"
# define PH_THINKING "is thinking"
# define PH_DIED "died"
# define PH_MONITORING_DELAY 500
# define PH_USLEEP_DELAY 500
# define PH_BUFSIZE 50
# define PH_MAX_SEM_NAME_LEN 24

# define PH_ERROR_INTRO "error: "
# define PH_ERR_WRONG_NUMBER_ARG "wrong number of arguments"
# define PH_ERR_WRONG_NUMBER_PHILO "wrong number of philosophers(must be > 1)"
# define PH_ERR_NOT_NUMERIC_ARG "all arguments must be numeric"
# define PH_ERR_FATAL "fatal error"

typedef struct		s_philosopher
{
	sem_t			*left_fork_sem;
	sem_t			*right_fork_sem;
	sem_t			*eat_time_sem;
	pthread_t		philo_thread;
	pthread_t		monitor_thread;
	int				i;
	int				last_eat_time;
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
	sem_t			*output_sem;
	int				some_philo_is_dead;
	long			start_time;
}					t_data;

extern t_data		g_data;

void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putstr_to_buf(char *s, char *buf);
void				ft_putnbr_to_buf(int n, char *buf);
int					ft_strcmp(char *s1, char *s2);
int					ft_isdigit(int c);

int					ph_error(char *msg);

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
void				print_status(int current_time, char *state,
								t_philosopher *philo);
void				generate_sem_name(char *base_name, int i, char *buf);

#endif
