/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:04:28 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/04 11:49:13 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Allocates and returns an array of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array ends by a NULL pointer.
** Returns the array of new strings resulting from the split or NULL if the
** allocation fails.
*/

static size_t	my_wordcounter(char const *s, char c);
static size_t	my_wordlength(char const *s, char c, size_t start);
static char		**my_wordcopy(char const *s, char c, char **prt);
static char		**my_malloc_error(char **ptr);

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (my_wordcounter(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = my_wordcopy(s, c, ptr);
	return (ptr);
}

static size_t	my_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			w++;
			i++;
		}
		else
			i++;
	}
	return (w);
}

static size_t	my_wordlength(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] != c && s[start + len] != '\0')
		len++;
	return (len);
}

static char	**my_wordcopy(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	w;
	size_t	j;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = my_wordlength(s, c, i);
			ptr[w] = ft_substr(s, i, j);
			if (ptr[w] == NULL)
				return (my_malloc_error(ptr));
			i = i + my_wordlength(s, c, i);
			w++;
		}
	}
	ptr[w] = NULL;
	return (ptr);
}

static char	**my_malloc_error(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
