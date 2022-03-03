/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsupernbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/02/11 12:09:37 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

/*
** writes 'n' as decimal or hexadecimal (depending on 'base')
** if hexadecimal, 'upper' defines if upper- or lowercase
** returns the number of written characters.
*/

int	ft_putsupernbr(long n, unsigned int base, int upper)
{
	int		returnvalue;
	char	*str0;
	char	*str1;
	char	c;

	str0 = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	returnvalue = 0;
	if (n < 0)
	{
		returnvalue += ft_putchar('-');
		n = n * -1;
	}
	if (n > (base - 1))
	{
		returnvalue += ft_putsupernbr(n / base, base, upper);
	}
	if (upper == 0)
		c = str0[n % base];
	else
		c = str1[n % base];
	returnvalue += write(1, &c, 1);
	return (returnvalue);
}
