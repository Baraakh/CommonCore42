# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 05:10:43 by bkhilo            #+#    #+#              #
#    Updated: 2025/10/31 10:14:36 by bkhilo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

# Source files
SRCS = ft_isalpha.c \
	ft_isdigit.c    \
	ft_isalnum.c    \
	ft_isascii.c    \
	ft_isprint.c    \
	ft_strlen.c     \
	ft_memset.c     \
	ft_bzero.c	    \
	ft_memcpy.c     \
	ft_memmove.c    \
	ft_strlcpy.c    \
	ft_strlcat.c    \
	ft_toupper.c    \
	ft_tolower.c    \
	ft_strchr.c     \
	ft_strrchr.c    \
	ft_strncmp.c    \
	ft_memchr.c     \
	ft_memcmp.c     \
	ft_strnstr.c    \
	ft_atoi.c		\
	ft_calloc.c		\
	ft_strdup.c

# Object files "substitution reference"
OBJS = $(SRCS:.c=.o)

HEADERS = libft.h

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) test_libft.c -L. -lft -o test_libft
	$(MAKE) fclean
	-./test_libft
	@rm -f test_libft