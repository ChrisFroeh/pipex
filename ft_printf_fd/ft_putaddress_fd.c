/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/07 16:33:31 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_fd.h"

/*
** writes 'n' as hexadecimal (lowercase)
** returns the number of written characters.
*/

int	ft_putaddress_fd(long unsigned int n, int fd)
{
	int		returnvalue;
	char	*str0;
	char	c;

	str0 = "0123456789abcdef";
	returnvalue = 0;
	if (n > 15)
	{
		returnvalue += ft_putaddress_fd(n / 16, fd);
	}
	c = str0[n % 16];
	returnvalue += write(fd, &c, 1);
	return (returnvalue);
}
