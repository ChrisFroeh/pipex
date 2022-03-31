/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:26:19 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/31 12:39:19 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 1/5
** Prints error message, frees allocated memory and exits.
*/

void	mischief_managed(t_data *data, int nbr, char *s, int x)
{
	ft_printf_fd(2, "%s: %s: %s\n", data->terminal, strerror(nbr), s);
	cleanup(data, x);
	exit(1);
}

/* 2/5
** Frees the pointer 'terminal' (i > 0) and the arrays 'path' (i > 1)
** and 'cmd' (i > 2) in the structure 'data'.
*/

void	cleanup(t_data *data, int x)
{
	int	i;

	i = 0;
	if (data->terminal != NULL)
		free(data->terminal);
	if (x > 1 && data->paths != NULL)
	{
		while (data->paths[i] != NULL)
		{
			free(data->paths[i]);
			i++;
		}
		free(data->paths);
	}
	i = 0;
	if (x > 2 && data->cmd != NULL)
	{
		while (data->cmd[i] != NULL)
		{
			free(data->cmd[i]);
			i++;
		}
		free(data->cmd);
	}
	return ;
}

/* 3/5
** Closes all open file descriptors and duplicates
** the reading-end of the pipe into the tmpfd.
*/

void	close_fds(t_data *data)
{
	close(data->input);
	close(data->output);
	close(data->tmpfd);
	close(data->fd[WRITE_END]);
	dup2(data->fd[READ_END], data->tmpfd);
	close(data->fd[READ_END]);
	return ;
}

/* 4/5
** Splits the command-flag string into an array of command and flag.
*/

char	**set_cmd(char *argv)
{
	char	**tmp;

	tmp = ft_split(argv, ' ');
	return (tmp);
}

/* 5/5
** Duplicates tmpfd back into the reading end of the pipe.
*/
void	set_fds(t_data *data)
{
	dup2(data->tmpfd, data->fd[READ_END]);
	close(data->tmpfd);
	return ;
}
