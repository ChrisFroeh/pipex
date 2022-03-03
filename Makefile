# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:29:35 by cfrohlic          #+#    #+#              #
#    Updated: 2022/03/02 17:21:16 by cfrohlic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c \
		childprocess.c

OBJS = ${SRCS:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = ft_printf/

all: subsystem ${NAME}

subsystem:
	@make	-C ${FT_PRINTF_PATH}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${FT_PRINTF_PATH}ft_printf.a -o ${NAME}

clean:
	@make -C ${FT_PRINTF_PATH} clean
	@rm -f ${OBJS}

fclean: clean
	@make -C ${FT_PRINTF_PATH} fclean
	@rm -f ${NAME}

re: fclean all
