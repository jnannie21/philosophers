CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
MAIN_SOURCES = 	main.c ft_atoi.c ft_calloc.c ft_strlen.c ft_putstr_fd.c		\
				errors.c
NAME = philo_one

OBJECTS = $(MAIN_SOURCES:.c=.o)
HEADER = philo_one.h

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
