/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:37:16 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/31 15:30:15 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 1/5
** Pipex main.
*/

int	main(int argc, char *argv[], char *envp[])
{
	int		status;
	t_data	data;

	data.terminal = set_terminal(envp);
	if (argc < 5)
		mischief_managed(&data, EINVAL, "not enough arguments", 1);
	data.tmpfd = 0;
	data.paths = set_paths(envp);
	split_process(&data, argc, argv, envp);
	close(data.tmpfd);
	waitpid(data.pid, &status, 0);
	while (wait(NULL) != -1)
		;
	return (WEXITSTATUS(status));
}

/* 2/5
** Forks the commands in child processes and creates pipes.
*/

void	split_process(t_data *data, int argc, char *argv[], char *envp[])
{
	int	i;

	i = argc - 4;
	while (i >= 0)
	{
		if (pipe(data->fd) == -1)
			mischief_managed(data, EPIPE, "pipe failure", 2);
		data->pid = fork();
		if (data->pid == -1)
			mischief_managed(data, ECHILD, "fork failure", 2);
		if (data->pid == 0)
		{
			if (i == argc - 4)
				open_infile(data, argv);
			else
				set_fds(data);
			if (i == 0)
				open_outfile(data, argv, argc);
			child_process(data, argv[(argc - 2 - i)], envp);
		}
		i--;
		close_fds(data);
	}
	return ;
}

/* 3/5
** Child process. Updates the command. Prints error message,
** frees allocated memory and exits if redirecting fails.
*/

void	child_process(t_data *data, char *argv, char *envp[])
{
	data->cmd = set_cmd(argv);
	if (redirecting_child(data, envp))
	{
		ft_printf_fd(2, "%s: %s\n", data->terminal, strerror(errno));
		cleanup(data, 3);
		exit(1);
	}
	return ;
}

/* 4/5
** Opens the Infile into the correct fd. Prints error message,
** frees allocated memory and exits if open fails.
*/

void	open_infile(t_data *data, char *argv[])
{
	data->input = open(argv[1], O_RDONLY);
	if (data->input == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", data->terminal,
			strerror(errno), argv[1]);
		cleanup(data, 2);
		exit(1);
	}
	else
	{
		dup2(data->input, data->fd[READ_END]);
		close(data->input);
		close(data->output);
	}
	return ;
}

/* 5/5
** Opens the outfile into the correct fd. Prints error message,
** frees allocated memory and exits if open fails.
*/

void	open_outfile(t_data *data, char *argv[], int argc)
{
	data->output = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->output == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", data->terminal,
			strerror(errno), argv[4]);
		cleanup(data, 2);
		exit(1);
	}
	else
	{
		dup2(data->output, data->fd[1]);
		close(data->input);
		close(data->output);
	}
	return ;
}
