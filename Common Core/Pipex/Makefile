CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = pipex
HEADER = pipex.h
OBJ_DIR = obj

SRCS = $(wildcard *.c) \
	   $(wildcard utils_libft/*.c) \
	   $(wildcard utils_pipex/*.c)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
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
