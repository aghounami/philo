NAME = philo
bonus = utils_philo_bonus.c  philo_bonus.c utils_bonus.c \
		monitor_bonus.c philosopher_bonus.c routine_bonus.c

OBJS = $(bonus:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo_bonus.h
	@cc $(FLAGS) $< -c -o $@
	@echo "\033[0;32m✅ Compiling $<\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31mCleaned 🧹\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mphilo removed 🧹\033[0m"

re: fclean all

.PHONY: clean
