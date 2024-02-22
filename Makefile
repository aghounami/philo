NAME = philo
SRCS =	utils_philo.c  philo.c utils.c monitor.c philosopher.c routine.c

# bonus = utils_philo_bonus.c  philo_bonus.c utils_bonus.c \
# 		monitor_bonus.c philosopher_bonus.c routine_bonus.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g

all: $(NAME)

bomus: 
	@cd bonus && make

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	@cc $(FLAGS) $< -c -o $@
	@echo "\033[0;32m✅ Compiling $<\033[0m"


clean:
	@rm -f $(OBJS)
	@echo "\033[0;31mCleaned 🧹\033[0m"
	@cd bonus && make clean

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mphilo removed 🧹\033[0m"
	@cd bonus && make fclean

re: fclean all 
	cd bonus && make re

push:
	@git add .
	@git commit -m "last update"
	@git push
	@echo "\033[0;31mpushed to git 🚀\033[0m\n"

.PHONY: clean
