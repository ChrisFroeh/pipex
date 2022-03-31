# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:29:35 by cfrohlic          #+#    #+#              #
#    Updated: 2022/03/31 16:08:43 by cfrohlic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	ft_split.c \
		ft_strdup.c \
		ft_substr.c \
		pipex_utils.c \
		pipex.c \
		redirecting_process.c \
		set_paths.c
BONSRCS = 	ft_split.c \
			ft_strdup.c \
			ft_substr.c \
			pipex_utils.c \
			pipex_bonus.c \
			redirecting_process.c \
			set_paths.c

OBJS = ${SRCS:.c=.o}
BONOBJS = ${BONSRCS:.c=.o}

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

bonus: pipex_bonus

pipex_bonus: ft_printf_fd/ft_printf_fd.a ${BONOBJS}
	${CC} ${FLAGS} ${BONOBJS} ${FT_PRINTF_PATH}ft_printf_fd.a -o pipex_bonus
	@printf "##### PIPEX_BONUS READY #####\n"

clean:
	@make -C ${FT_PRINTF_PATH} clean
	@rm -f ${OBJS}
	@rm -f ${BONOBJS}

fclean: clean
	@make -C ${FT_PRINTF_PATH} fclean
	@rm -f ${NAME}
	@rm -f pipex_bonus

re: fclean all
