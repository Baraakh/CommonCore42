NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.

SRCS	= srcs/main.c \
		  srcs/parse.c \
		  srcs/parse_utils.c \
		  srcs/stack_utils.c \
		  srcs/operations_utils.c \
		  srcs/operations_a.c \
		  srcs/operations_b.c \
		  srcs/operations_both.c \
		  srcs/sort_small.c \
		  srcs/sort_five.c \
		  srcs/sort_radix.c

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
