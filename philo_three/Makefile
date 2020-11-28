CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -pthread
MAIN_SOURCES = 	main.c ft_atoi.c ft_calloc.c ft_strlen.c ft_putstr_to_buf.c	\
				ft_putnbr_to_buf.c ft_strcmp.c ph_philo_lifecycle.c			\
				ph_errors.c ph_time.c ph_monitoring.c ph_change_state.c		\
				ph_threads.c ph_init_philosophers.c ph_usleep.c				\
				ph_read_settings.c ph_destroy_philosophers.c ft_isdigit.c	\
				ph_print_status.c ph_generate_sem_name.c ph_open_sem.c
NAME = philo_three

OBJECTS = $(MAIN_SOURCES:.c=.o)
HEADER = philo.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONEY: all clean fclean re
