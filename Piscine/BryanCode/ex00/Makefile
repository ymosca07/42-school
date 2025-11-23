NAME = rush-02
CC   = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes
SRC = srcs/main.c srcs/file.c srcs/utils.c srcs/dup.c srcs/dict_pars.c srcs/dict_utils.c srcs/print_groups.c srcs/print_utlis.c srcs/print.c srcs/groups.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c includes/header.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
