CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HEADER = so_long.h
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11

SRCS = main.c \
	   actions/inputs.c \
	   functions_utils/copy_map.c \
	   functions_utils/free_tab.c \
	   functions_utils/ft_strlen.c \
	   parsing/get_height_map.c \
	   parsing/player_position.c \
	   parsing/read_map.c \
	   sprites/aff_sprites.c \
	   sprites/load_sprites.c \
	   verifications/ber_extension.c \
	   verifications/check_stuff.c \
	   verifications/end_possible.c \
	   verifications/error_signal.c \
	   verifications/flood_fill.c \
	   verifications/free_struct.c \
	   verifications/map_len.c \
	   verifications/wall_check.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \
	   printf/ft_printf.c \
	   printf/search_type.c \
	   printf/functions_utils.c \
	   printf/functions2_utils.c
	   
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
