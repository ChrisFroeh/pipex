/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:37:16 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 18:10:15 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_cmd	*cmdlist;
	int		fd[2];
	int		pid1;
	int		pid2;
	char	*envp[6] = {"/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin", "/sbin", "/usr/local/munki"};

	if (argc != 5)
		return (1);

	cmdlist = NULL;
	if (!init_cmds(argv, &cmdlist, envp))
	{
		ft_printf("initialisation succeeded\n");
	}
	else
		ft_printf("initialisation failed\n");

	ft_printf("cmd1: %s\tcmd2: %s\n", cmdlist->cmd, cmdlist->next->cmd);
	ft_printf("path1: %s\tpath2: %s\n", cmdlist->path, cmdlist->next->path);
	ft_destroy_cmdlist(&cmdlist);


	/*

	if(pipe(fd) == -1)
		return (2);
	input = open(argv[1], O_RDONLY | O_CREAT, 0777);
	output = open(argv[4], O_WRONLY | O_CREAT, 0777);
	fd[0] = dup2(input, STDIN_FILENO);
	fd[1] = dup2(output, STDOUT_FILENO);



	pid1 = fork();
	if (pid1 == -1)
		return (3);

	if (pid1 == 0)
	{
		// child process 1 (cmd1)
		close(fd[0]);
		close(fd[1]);
		if (childprocess_a(argv, envp, &fd))
		{
			ft_printf("Fail in child process 1\n");
			return (4);
		}
		return (1);
	}

	pid2 = fork();
	if (pid2 == -1)
		return (4);

	if (pid2 == 0)
	{
		// child process 2 (cmd2)
		close(fd[0]);
		close(fd[1]);
		if (childprocess_b(argv, envp, &fd))
		{
			ft_printf("Fail in child process 2\n");
			return (5);
		}
		return (1);
	}


	else
	{
		// parent process
		close(fd[0]);
		close(fd[1]);
		ft_printf("Waiting for child processes...\n");
		wait(NULL);
		wait(NULL);
		ft_printf("Finished\n");
	}
	*/


	return (0);
}
