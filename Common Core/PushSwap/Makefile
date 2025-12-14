CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
HEADER = push_swap.h

SRCS = main.c \
	   nodes/ft_lstadd_back.c \
	   nodes/ft_lstnew.c \
	   parsing/ft_is_in.c \
	   parsing/init_split_stack.c \
	   parsing/parsing.c \
	   functions_utils/ft_atol.c \
	   functions_utils/ft_count_len.c \
	   functions_utils/ft_split.c \
	   functions_utils/ft_strlen.c \
	   functions_utils/ft_substr.c \
	   operations/sa.c \
	   operations/sb.c \
	   operations/ss.c \
	   operations/ra.c \
	   operations/rb.c \
	   operations/rr.c \
	   operations/rra.c \
	   operations/rrb.c \
	   operations/rrr.c \
	   operations/pa.c \
	   operations/pb.c \
	   operations/_ra.c \
	   operations/_rb.c \
	   operations/_rra.c \
	   operations/_rrb.c \
	   operations/_sa.c \
	   operations/_sb.c \
	   push_swap.c \
	   nodes/ft_lstadd_front.c \
	   nodes/init_stack_a.c \
	   algo/sort_2.c \
	   algo/sort_3.c \
	   algo/sort_5.c \
	   algo/push_max.c \
	   algo/push_min.c \
	   algo/search_min_max.c \
	   nodes/ft_lstsize.c \
	   algo/chunk_sort.c \
	   algo/utils_chunk.c \
	   parsing/last_verif.c \
	   parsing/signs.c \
	   parsing/ft_strcmp.c \
	   nodes/ft_lstclear.c \
	   parsing/check_empty_string.c
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re