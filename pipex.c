/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:37:16 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 15:37:04 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	pid_t	pid;

	data.terminal = set_terminal(envp);
	data.paths = set_paths(envp);
	if (argc != 5)
		mischief_managed(&data, EINVAL, "not enough arguments");
	open_files(&data, argv);
	if (pipe(data.fd) == -1)
		mischief_managed(&data, EPIPE, "pipe failure");
	pid = fork();
	if (pid == -1)
		mischief_managed(&data, ECHILD, "fork failure");
	if (pid == 0)
		child_process(&data, argv, envp);
	wait(NULL);
	parent_process(&data, argv, envp);
	close(data.fd[WRITE_END]);
	close(data.fd[READ_END]);
	return (0);
}

void	child_process(t_data *data, char *argv[], char *envp[])
{
	data->cmd = set_cmd(argv, 2);
	if (redirecting_child(data, envp))
	{
		ft_printf_fd(2, "%s: %s\n", data->terminal, strerror(errno));
		cleanup(data);
		exit(1);
	}
	return ;
}

void	parent_process(t_data *data, char *argv[], char *envp[])
{
	data->cmd = set_cmd(argv, 3);
	if (redirecting_parent(data, envp))
	{
		ft_printf_fd(2, "%s: %s\n", data->terminal, strerror(errno));
		cleanup(data);
		exit(1);
	}
	return ;
}

void	open_files(t_data *data, char *argv[])
{
	data->input = open(argv[1], O_RDONLY);
	if (data->input == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", data->terminal,
			strerror(errno), argv[1]);
		cleanup(data);
		if (errno == 13)
			exit(0);
		exit(1);
	}
	data->output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->output == -1)
	{
		close(data->input);
		ft_printf_fd(2, "%s: %s: %s\n", data->terminal,
			strerror(errno), argv[4]);
		cleanup(data);
		exit(1);
	}
	return ;
}
