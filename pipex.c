/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:37:16 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 10:41:34 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		return (1);
	if(pipe(fd) == -1)
		return (2);
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

	return (0);
}
