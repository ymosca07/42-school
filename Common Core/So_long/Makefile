CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
HEADER = so_long.h

SRCS = $(wildcard *.c) \
	   $(wildcard parsing/*.c) \
	   $(wildcard verifications/*.c) \
	   $(wildcard functions_utils/*.c) \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "Compilation réussie !"
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
