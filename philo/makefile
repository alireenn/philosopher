NAME=philo

CC=gcc

FLAGS=-Wall -Werror -Wextra #-fsanitize=address -g3

SRC=utils.c start.c init_or_destroy63.c utils2.c utils3.c

MAIN=philosopher.c

OBJS=$(SRC:.c=.o)
MAINO=$(MAIN:.c=.o)

$(NAME): $(OBJS) $(MAINO)
	$(CC) $(FLAGS) $(SRC) $(MAIN) -o $(NAME)

all: $(NAME)

clean:
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mPhilosopher>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mPhilosopher>> Project cleaned\033[0m"

re: fclean all
	@echo "\033[0;92mPhilosopher>> Project cleaned and recompiled\033[0m"

.PHONY: all clean fclean re