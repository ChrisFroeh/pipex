/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/07 16:33:59 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

/*
** writes the characters in 'input' string
** if '%' appears the conversion gets checked for "cspdiuxX%"
** returns the number of written characters.
*/

int	ft_printf_fd(int fd, const char *input, ...)
{
	size_t	i;
	va_list	arguments;
	int		returnvalue;

	i = 0;
	returnvalue = 0;
	va_start(arguments, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			returnvalue += ft_checkconversion_fd(input[i + 1], arguments, fd);
			i = i + 2;
		}
		else
		{
			returnvalue += write(fd, &input[i], 1);
			i++;
		}
	}
	va_end(arguments);
	return (returnvalue);
}
