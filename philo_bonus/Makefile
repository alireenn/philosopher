NAME=philo_bonus

CC=gcc

FLAGS=-Wall -Werror -Wextra #-fsanitize=address -g3

SRC=init_bonus.c utils_bonus.c start_bonus.c utils2_bonus.c

MAIN=philo_bonus.c

OBJS=$(SRC:.c=.o)
MAINO=$(MAIN:.c=.o)

$(NAME): $(OBJS) $(MAINO)
	$(CC) $(FLAGS) $(SRC) $(MAIN) -o $(NAME)

all: $(NAME)

clean:
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mPhilo_bonus>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mPhilo_bonus>> Project cleaned\033[0m"

re: fclean all
	@echo "\033[0;92mPhilo_bonus>> Project cleaned and recompiled\033[0m"

.PHONY: all clean fclean re