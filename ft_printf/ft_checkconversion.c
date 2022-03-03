/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2021/10/26 10:09:19 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

/*
** checks the character after '%' and decides further action
** returns the number of written characters.
*/

int	ft_checkconversion(char conversion, va_list arguments)
{
	int		returnvalue;

	returnvalue = 0;
	if (conversion == 'c')
		returnvalue += ft_putchar(va_arg(arguments, int));
	else if (conversion == 's')
		returnvalue += ft_putstr(va_arg(arguments, char *));
	else if (conversion == 'p')
	{
		returnvalue += write(1, "0x", 2);
		returnvalue += ft_putaddress(va_arg(arguments, long long));
	}
	else if (conversion == 'd' || conversion == 'i')
		returnvalue += ft_putsupernbr(va_arg(arguments, int), 10, 0);
	else if (conversion == 'u')
		returnvalue += ft_putsupernbr(va_arg(arguments, unsigned int), 10, 0);
	else if (conversion == 'x')
		returnvalue += ft_putsupernbr(va_arg(arguments, unsigned int), 16, 0);
	else if (conversion == 'X')
		returnvalue += ft_putsupernbr(va_arg(arguments, unsigned int), 16, 1);
	else if (conversion == '%')
		returnvalue += write(1, "%", 1);
	return (returnvalue);
}
