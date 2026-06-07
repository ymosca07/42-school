CC = cc
CFLAGS = -g -pthread -Wall -Wextra -Werror
NAME = philo
HEADER = philo.h \
		 struct.h
OBJ_DIR = obj

SRCS = $(wildcard *.c) \
	   $(wildcard parsing/*.c) \
	   $(wildcard errors/*.c) \
	   $(wildcard utils/*.c)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation réussie !"
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
	@echo "Tout est clean !"

re: fclean all

.PHONY: all clean fclean re
