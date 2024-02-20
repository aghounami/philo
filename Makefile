NAME = philo
SRCS =	utils_philo.c  philo.c utils.c monitor.c philosopher.c routine.c
# bonus: utils_philo_bonus.c  philo_bonus.c utils_bonus.c \
# 		monitor_bonus.c philosopher_bonus.c routine_bonus.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	@cc $(FLAGS) $< -c -o $@
	@echo "✅ Compiling $<"
	@echo "\033[4;35m\..................\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo "philo removed 🧹"

re: fclean all

push:
	@git add .
	@git commit -m "last update"
	@git push
	@echo "\033[0;31mpushed to git 🚀\033[0m\n"



.PHONY: clean
