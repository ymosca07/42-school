CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
HEADER = so_long.h
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11

SRCS = $(wildcard *.c) \
	   $(wildcard parsing/*.c) \
	   $(wildcard verifications/*.c) \
	   $(wildcard functions_utils/*.c) \
	   $(wildcard sprites/*.c) \
	   $(wildcard actions/*.c) \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "Compilation réussie !"
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
