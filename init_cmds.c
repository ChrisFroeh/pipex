/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:29:53 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 18:08:56 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_cmds(char *argv[], t_cmd **cmdlist, char *envp[])
{
	ft_init_lst(cmdlist, ft_lstnew(argv[2], envp));
	ft_lstaddback(cmdlist, ft_lstnew(argv[3], envp));
	return (0);
}

void	ft_init_lst(t_cmd **cmdlist, t_cmd *new)
{
	t_cmd	*tmp;

	if (new == NULL || cmdlist == NULL)
		return ;
	if (*cmdlist == NULL)
	{
		*cmdlist = new;
		new->next = NULL;
		return ;
	}
	tmp = *cmdlist;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = NULL;
	return ;
}

t_cmd	*ft_lstnew(char *argv, char *envp[])
{
	t_cmd	*element;

	element = (t_cmd *)malloc(sizeof(t_cmd));
	if (element == NULL)
		return (NULL);
	element->next = NULL;
	element->path = *envp; // ??
	element->cmd = argv;
	element->input = 0;
	element->output = 0;
	return (element);
}

void	ft_lstaddback(t_cmd **cmdlist, t_cmd *new)
{
	t_cmd	*tmp;

	if (new == NULL || cmdlist == NULL)
		return ;
	if (*cmdlist == NULL)
	{
		*cmdlist = new;
		new->next = NULL;
		return ;
	}
	tmp = *cmdlist;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = NULL;
	return ;
}

void	ft_destroy_cmdlist(t_cmd **cmdlist)
{
	t_cmd	*current;
	t_cmd	*next;

	if (cmdlist)
	{
		current = *cmdlist;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*cmdlist = NULL;
	}
}