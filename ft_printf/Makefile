# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 18:04:54 by bkhilo            #+#    #+#              #
#    Updated: 2025/12/08 18:13:02 by bkhilo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c	\
	ft_putchar.c	\
	ft_putstr.c		\
	ft_putptr.c		\
	ft_putnbr.c		\
	ft_putunbr.c	\
	ft_puthex.c	

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)	

re: fclean all

.PHONY: all clean fclean re bonus	