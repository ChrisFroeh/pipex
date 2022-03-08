/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:12:27 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 12:48:01 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "ft_printf_fd/ft_printf_fd.h"

# define READ_END 0
# define WRITE_END 1

typedef struct s_data
{
	char	**paths;
	char	**cmd;
	char	*terminal;
	int		input;
	int		output;
	int		fd[2];
}		t_data;

char	**set_paths(char *envp[]);
char	*search_path(char *envp[], char *str, int j);
char	*set_terminal(char *envp[]);
char	**set_cmd(char *argv[], int i);

void	mischief_managed(t_data *data, int nbr, char *s);

void	open_files(t_data *data, char *argv[]);
void	child_process(t_data *data, char *argv[], char *envp[]);
void	parent_process(t_data *data, char *argv[], char *envp[]);
int		redirecting_child(t_data *data, char *envp[]);
int		redirecting_parent(t_data *data, char *envp[]);

int		cmd_execution(t_data *data, char *envp[]);
char	*find_executable(t_data *data);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

void	cleanup(t_data *data);

#endif
