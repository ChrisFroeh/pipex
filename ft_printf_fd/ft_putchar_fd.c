/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:58 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/07 16:33:08 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** writes the character 'c'
** returns the number of written characters.
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
