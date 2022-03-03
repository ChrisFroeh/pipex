/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:29:20 by cfrohlic          #+#    #+#             */
/*   Updated: 2021/10/26 09:57:48 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putsupernbr(long n, unsigned int base, int upper);
int		ft_putaddress(long unsigned int n);
int		ft_checkconversion(char conversion, va_list arguments);
#endif
