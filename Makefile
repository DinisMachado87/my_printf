# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:05:13 by dimachad          #+#    #+#              #
#    Updated: 2025/01/13 18:17:48 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
SRC =		libftprintf.c \
			ft_strlen.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putbase.c \
			ft_putstr_fd.c
OBJS =		$(SRC:.c=.o)
INC_DIR =	.
CPPFLAGS =	-I$(INC_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.c ft_printf.h
			$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
