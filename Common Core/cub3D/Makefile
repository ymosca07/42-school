NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_DIR     = minilibx-linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

INCLUDES    = -I. -I$(MLX_DIR) -Iparsing -Iget_next_line -Iutils -Iexec -Ifree

SRCS        = main.c \
              exec/draw/draw.c \
              exec/draw/crosshair.c \
              exec/minimap/minimap.c \
              exec/endgame.c \
              exec/movements/keys.c \
              exec/movements/mouse_move.c \
              exec/movements/movements.c \
              exec/raycast.c \
              exec/render.c \
              exec/textures.c \
              exec/doors/init_doors.c \
              exec/doors/doors.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c \
              parsing/cub_extension.c \
              parsing/fill_data.c \
              parsing/fill_input.c \
              parsing/fill_map.c \
              parsing/find.c \
              parsing/parsing.c \
              parsing/rgb_verif.c \
              utils/ft_atoi.c \
              utils/ft_split.c \
              utils/ft_strjoin.c \
              utils/ft_strlen.c \
              utils/ft_substr.c \
              utils/ft_memset.c \
              free/all_free_error.c \
              free/all_free.c \
              free/double_tab.c \
              maps/authorize_char.c \
              maps/conform_map.c \
              maps/count_positions.c \
              maps/maps.c \
              maps/neighbor.c \
              maps/player_struct.c

OBJ_DIR     = obj
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME)

clean:
	@-make -C $(MLX_DIR) clean 2>/dev/null || true
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
