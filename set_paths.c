/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrohlic <cfrohlic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:31:21 by cfrohlic          #+#    #+#             */
/*   Updated: 2022/03/08 12:24:11 by cfrohlic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Splits the string with the multiple paths into an array of single paths.
*/

char	**set_paths(char *envp[])
{
	char	**tmp;
	char	*str;
	int		i;

	str = search_path(envp, "PATH=", 5);
	tmp = ft_split(str, ':');
	i = 0;
	while (tmp[i] != NULL)
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		i++;
	}
	return (tmp);
}

/*
** Splits the string into an array of single strings and returns the last one.
*/

char	*set_terminal(char *envp[])
{
	char	**tmp;
	char	*str;
	char	*terminal;
	int		i;

	str = search_path(envp, "SHELL=/", 7);
	tmp = ft_split(str, '/');
	i = 0;
	while (tmp[i + 1] != NULL)
		i++;
	terminal = ft_strdup(tmp[i]);
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (terminal);
}

/*
** Searches for the line starting with "PATH=" in 'envp'
** and returns the string after '='.
*/

char	*search_path(char *envp[], char *str, int j)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(str, envp[i], j) == 0)
			return (envp[i] + j);
		i++;
	}
	return (envp[i]);
}

/*
** Compares not more than 'n' characters of the null-terminated strings 's1'
** and 's2'.
** Returns an integer greater than, equal to, or less than 0, according as the
** string 's1' is greater than, equal to, or less than the string 's2'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && i < (n - 1) && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
		i++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 - *str2);
}

/*
** Allocates and returns a new string 'ptr', which is the result of the
** concatenation of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	n = 0;
	while (s1[n] != '\0')
	{
		ptr[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[n] = s2[i];
		n++;
		i++;
	}
	ptr[n] = '\0';
	return (ptr);
}
