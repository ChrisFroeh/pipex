/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:10:48 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/03 10:42:41 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	childprocess_a(char *argv[], char *envp[], int *fd)
{
	int	filedes;

	filedes = open(argv[1], O_RDONLY);
	if (filedes == -1)
	{
		ft_printf("Failure on opening input\n");
		return (1);
	}
	if(write(fd[0]))


	ft_printf("Child porcess a in progress\n");
	ft_printf("%s\n", argv[2]);
	return (0);
}

int	childprocess_b(char *argv[], char *envp[], int *fd)
{


	ft_printf("Child porcess b in progress\n");
	ft_printf("%s\n", argv[2]);
	return (0);
}
