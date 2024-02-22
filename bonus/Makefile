NAME = philo
bonus = utils_philo_bonus.c  philo_bonus.c utils_bonus.c \
		monitor_bonus.c philosopher_bonus.c routine_bonus.c

OBJS = $(bonus:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo_bonus.h
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

.PHONY: clean
