/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:26:19 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/09 17:23:30 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 1/3
** Frees the arrays 'path' and 'cmd' and the pointer 'terminal'
** in the structure 'data'.
*/

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	if (data->paths != NULL)
	{
		while (data->paths[i] != NULL)
		{
			free(data->paths[i]);
			i++;
		}
		free(data->paths);
	}
	i = 0;
	if (data->cmd != NULL)
	{
		while (data->cmd[i] != NULL)
		{
			free(data->cmd[i]);
			i++;
		}
		free(data->cmd);
	}
	if (data->terminal != NULL)
		free(data->terminal);
	return ;
}

/* 2/3
** Prints error message, frees allocated memory and exits.
*/

void	mischief_managed(t_data *data, int nbr, char *s)
{
	ft_printf_fd(2, "%s: %s: %s\n", data->terminal, strerror(nbr), s);
	cleanup(data);
	exit(1);
}

/* 3/3
** Splits the command-flag string into an array of command and flag.
*/

char	**set_cmd(char *argv[], int i)
{
	char	**tmp;

	tmp = ft_split(argv[i], ' ');
	return (tmp);
}
