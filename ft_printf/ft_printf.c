/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/01/13 12:27:48 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

/*
** writes the characters in 'input' string
** if '%' appears the conversion gets checked for "cspdiuxX%"
** returns the number of written characters.
*/

int	ft_printf(const char *input, ...)
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
			returnvalue += ft_checkconversion(input[i + 1], arguments);
			i = i + 2;
		}
		else
		{
			returnvalue += write(1, &input[i], 1);
			i++;
		}
	}
	va_end(arguments);
	return (returnvalue);
}
