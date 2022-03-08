/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:29:20 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/07 16:29:46 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf_fd(int fd, const char *input, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putsupernbr_fd(long n, unsigned int base, int upper, int fd);
int		ft_putaddress_fd(long unsigned int n, int fd);
int		ft_checkconversion_fd(char conversion, va_list arguments, int fd);
#endif
