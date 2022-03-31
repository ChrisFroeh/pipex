/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecting_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:49:27 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/31 12:40:23 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 1/4
** Closes and duplicates the file descriptors for child process.
*/

int	redirecting_child(t_data *data, char *envp[])
{
	int	error;

	error = (
			dup2(data->fd[READ_END], STDIN_FILENO) == -1
			|| close(data->fd[READ_END]) == -1
			|| dup2(data->fd[WRITE_END], STDOUT_FILENO) == -1
			|| close(data->fd[WRITE_END]) == -1
			);
	if (error == 0)
		error = cmd_execution(data, envp);
	return (error);
}

/* 1/4
** Closes and duplicates the file descriptors for the last child process.
*/

int	redirecting_last_child(t_data *data, char *envp[])
{
	int	error;

	error = (
			dup2(data->fd[READ_END], STDIN_FILENO) == -1
			|| close(data->fd[READ_END]) == -1
			|| close(data->fd[WRITE_END]) == -1
			|| dup2(data->output, STDOUT_FILENO) == -1
			|| close(data->output) == -1
			);
	if (error == 0)
		error = cmd_execution(data, envp);
	return (error);
}

/* 3/4
** Executes the command, when it was found.
*/

int	cmd_execution(t_data *data, char *envp[])
{
	char	*cmd_path;

	cmd_path = find_executable(data);
	if (cmd_path == NULL)
	{
		ft_printf_fd(2, "%s: command not found: %s\n",
			data->terminal, data->cmd[0]);
		cleanup(data, 'a');
		exit(127);
	}
	else
		execve(cmd_path, data->cmd, envp);
	close(data->fd[WRITE_END]);
	close(data->fd[READ_END]);
	return (-1);
}

/* 4/4
** Searches in the paths for the command.
*/

char	*find_executable(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->paths && data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], data->cmd[0]);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}
