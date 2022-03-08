# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:29:35 by cfrohlic          #+#    #+#              #
#    Updated: 2022/03/07 19:01:44 by cfrohlic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf_fd.a

SRCS =	ft_printf_fd.c \
		ft_checkconversion_fd.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putaddress_fd.c \
		ft_putsupernbr_fd.c

OBJS = ${SRCS:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${FLAGS} -g -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
