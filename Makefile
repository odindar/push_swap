NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

SRCS        = main.c \
              ops/ops_push.c \
              ops/ops_reverse_rotate.c \
              ops/ops_rotate.c \
              ops/ops_swap.c \
              simple/next_simple.c \
              simple/sort_small.c \
              utils/libft_utils.c \
              utils/lst_utils.c \
              utils/node_utils.c \
              utils/sort_utils.c \
              utils/parse_utils.c \
              helper_func/disorder.c \
              helper_func/print.c \
              helper_func/ft_split.c \
              medium/k_sort.c \
              complex/radix.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:			clean all

.PHONY:		all clean fclean re
