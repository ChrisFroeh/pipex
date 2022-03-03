/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:12:27 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 11:30:58 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

typedef struct s_cmd
{
	struct s_cmd	*next;
	char 			*path;
}				t_cmd;


int		childprocess_a(char *argv[], char *envp[], int *fd);
int		childprocess_b(char *argv[], char *envp[], int *fd);


#endif
