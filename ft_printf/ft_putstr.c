/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2021/10/26 10:07:44 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** writes the string 'str' or "(null)" if 'str' is NULL
** returns the number of written characters.
*/

int	ft_putstr(char *str)
{
	int		returnvalue;

	returnvalue = 0;
	if (str == NULL)
	{
		returnvalue += write(1, "(null)", 6);
		return (returnvalue);
	}
	while (*str != '\0')
	{
		returnvalue += write(1, str, 1);
		str++;
	}
	return (returnvalue);
}
