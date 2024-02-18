NAME = philo
SRCS =	utils_philo.c  philo.c utils.c monitor.c philosopher.c routine.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	@cc $(FLAGS) $< -c -o $@
	@echo "✅ Compiling $<"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo "philo removed 🧹"

re: fclean all

.PHONY: clean
