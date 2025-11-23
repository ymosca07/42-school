CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = ft_printf.c \
	   functions_utils.c \
	   functions2_utils.c \
	   search_type.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re