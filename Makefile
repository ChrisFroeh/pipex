# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:29:35 by cfrohlic          #+#    #+#              #
#    Updated: 2022/03/08 12:27:19 by cfrohlic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	cleanup.c \
		ft_split.c \
		ft_strdup.c \
		ft_substr.c \
		mischief_manager.c \
		pipex.c \
		redirecting_process.c \
		set_cmd.c \
		set_paths.c

OBJS = ${SRCS:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = ft_printf_fd/

.c.o:
	@${CC} ${FLAGS} -g -c $< -o $@

${NAME}: ft_printf_fd/ft_printf_fd.a ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${FT_PRINTF_PATH}ft_printf_fd.a -o ${NAME}
	@printf "##### PIPEX READY #####\n"

ft_printf_fd/ft_printf_fd.a:
	@make	-C ${FT_PRINTF_PATH}

all: ${NAME}

clean:
	@make -C ${FT_PRINTF_PATH} clean
	@rm -f ${OBJS}

fclean: clean
	@make -C ${FT_PRINTF_PATH} fclean
	@rm -f ${NAME}

re: fclean all
