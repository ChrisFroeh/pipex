/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mischief_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:47:30 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 12:32:15 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mischief_managed(t_data *data, int nbr, char *s)
{
	ft_printf_fd(2, "%s: %s: %s\n", data->terminal, strerror(nbr), s);
	cleanup(data);
	exit(1);
}
