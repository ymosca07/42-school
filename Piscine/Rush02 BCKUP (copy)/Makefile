NAME = rush-02
CC   = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes
SRC = srcs/main.c srcs/file.c srcs/utils.c srcs/utils_II.c srcs/parsing.c srcs/dictlen.c
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

