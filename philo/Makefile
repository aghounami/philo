NAME = philo
SRCS =	utils_philo.c  philo.c utils.c monitor.c philosopher.c routine.c

OBJS = $(SRCS:.c=.o)

Cflags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(Cflags) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	@cc $(Cflags) $< -c -o $@
	@echo "\033[0;32m✅ Compiling $<\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31mCleaned 🧹\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mphilo removed 🧹\033[0m"

re: fclean all

.PHONY: clean
