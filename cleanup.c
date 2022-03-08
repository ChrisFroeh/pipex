/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:26:19 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 16:04:42 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
