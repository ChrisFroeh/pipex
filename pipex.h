/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:12:27 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 18:07:25 by cfrohlic         ###   ########.fr       */
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
	char			*cmd;
	int				input;
	int				output;
}				t_cmd;


//int		childprocess_a(char *argv[], char *envp[], int *fd);
//int		childprocess_b(char *argv[], char *envp[], int *fd);
int		init_cmds(char *argv[], t_cmd **cmdlist, char *envp[]);
void	ft_init_lst(t_cmd **cmdlist, t_cmd *new);
t_cmd	*ft_lstnew(char *argv, char *envp[]);
void	ft_lstaddback(t_cmd **cmdlist, t_cmd *new);
void	ft_destroy_cmdlist(t_cmd **cmdlist);

#endif
