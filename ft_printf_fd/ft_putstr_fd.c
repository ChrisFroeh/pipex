/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/07 16:31:43 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** writes the string 'str' or "(null)" if 'str' is NULL
** returns the number of written characters.
*/

int	ft_putstr_fd(char *str, int fd)
{
	int		returnvalue;

	returnvalue = 0;
	if (str == NULL)
	{
		returnvalue += write(fd, "(null)", 6);
		return (returnvalue);
	}
	while (*str != '\0')
	{
		returnvalue += write(fd, str, 1);
		str++;
	}
	return (returnvalue);
}
