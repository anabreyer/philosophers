NAME = philo

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror -g3
LDLIBS      := -lpthread

INC = ./include/philo.h

SRC = \
	./srcs/main.c \
	./srcs/checkargs.c \
	./srcs/init.c \
	./srcs/sim_utils.c \
	./srcs/simulation.c \
	./srcs/simulator.c \
	./srcs/time_utils.c \
	./srcs/utils.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
