NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= main.c \
			  ops_push.c \
			  ops_reverse_rotate.c \
			  ops_rotate.c \
			  ops_swap.c \
			  next_simple.c \
			  libft_utils.c \
			  lst_utils.c \
			  node_utils.c \
			  sort_utils.c \
			  disorder.c \
			  print.c \
			  k_sort.c \
			  radix.c

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
