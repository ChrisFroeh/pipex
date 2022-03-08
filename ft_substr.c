/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:58:22 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/04 11:51:06 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Allocates and returns a substring from the string ’s’. The substring begins
** at index ’start’ and is of maximum size ’len’.
** Returns substring 'ptr' or NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		n;

	if (s == NULL)
		return (NULL);
	n = 0;
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (n < len && s[start] != '\0')
	{
		ptr[n] = s[start];
		n++;
		start++;
	}
	ptr[n] = '\0';
	return (ptr);
}

/*
** Computes and returns the length of the string 's'.
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
