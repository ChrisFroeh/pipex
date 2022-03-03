/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2021/10/26 10:08:57 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

/*
** writes 'n' as hexadecimal (lowercase)
** returns the number of written characters.
*/

int	ft_putaddress(long unsigned int n)
{
	int		returnvalue;
	char	*str0;
	char	c;

	str0 = "0123456789abcdef";
	returnvalue = 0;
	if (n > 15)
	{
		returnvalue += ft_putaddress(n / 16);
	}
	c = str0[n % 16];
	returnvalue += write(1, &c, 1);
	return (returnvalue);
}
