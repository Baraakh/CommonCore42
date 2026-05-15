NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.

SRCS	= srcs/main.c \
		  srcs/parse.c \
		  srcs/list.c \
		  srcs/utils.c \
		  srcs/position.c \
		  srcs/ops_swap_push.c \
		  srcs/ops_rotate.c \
		  srcs/ops_rev_rotate.c \
		  srcs/sort_small.c \
		  srcs/sort_chunk.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
