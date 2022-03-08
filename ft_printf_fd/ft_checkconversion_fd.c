/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconversion_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 12:25:00 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

/*
** checks the character after '%' and decides further action
** returns the number of written characters.
*/

int	ft_checkconversion_fd(char conversion, va_list arguments, int fd)
{
	int		rval;

	rval = 0;
	if (conversion == 'c')
		rval += ft_putchar_fd(va_arg(arguments, int), fd);
	else if (conversion == 's')
		rval += ft_putstr_fd(va_arg(arguments, char *), fd);
	else if (conversion == 'p')
	{
		rval += write(fd, "0x", 2);
		rval += ft_putaddress_fd(va_arg(arguments, long long), fd);
	}
	else if (conversion == 'd' || conversion == 'i')
		rval += ft_putsupernbr_fd(va_arg(arguments, int), 10, 0, fd);
	else if (conversion == 'u')
		rval += ft_putsupernbr_fd(va_arg(arguments, unsigned int), 10, 0, fd);
	else if (conversion == 'x')
		rval += ft_putsupernbr_fd(va_arg(arguments, unsigned int), 16, 0, fd);
	else if (conversion == 'X')
		rval += ft_putsupernbr_fd(va_arg(arguments, unsigned int), 16, 1, fd);
	else if (conversion == '%')
		rval += write(fd, "%", 1);
	return (rval);
}
