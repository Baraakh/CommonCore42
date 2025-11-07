# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 05:10:43 by bkhilo            #+#    #+#              #
#    Updated: 2025/11/07 06:40:58 by bkhilo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
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
	ft_strdup.c		\
	ft_substr.c		\
	ft_strjoin.c	\
	ft_strtrim.c    \
	ft_split.c		\
	ft_itoa.c		\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_putchar_fd.c \
	ft_putstr_fd.c  \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# Bonus files
BONUS = ft_lstnew.c		\
	ft_lstadd_front.c	\
	ft_lstadd_back.c	\
	ft_lstdelone.c		\
	ft_lstclear.c		\
	ft_lstiter.c		\
	ft_lstmap.c			\
	ft_lstsize.c		\
	ft_lstlast.c

# Object files "substitution reference"
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = ${BONUS:.c=.o}

HEADERS = libft.h

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)	

re: fclean all

test: bonus 
	$(CC) $(CFLAGS) test_libft.c -L. -lft -o test_libft
	$(MAKE) fclean
	-./test_libft
	@rm -f test_libft

.PHONY: all clean fclean re bonus test	