/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:38 by nromito           #+#    #+#             */
/*   Updated: 2023/12/13 17:37:06 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (++i);
		i++;
	}
	return (0);
}

char	*str_join_mod(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc(len1 + len2 + 1, 1);
	if (join == NULL)
		return (NULL);
	i = -1;
	if (s1 == NULL)
	{
		while (s2[++i])
			join[len1++] = s2[i];
		return (join);
	}
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[len1++] = s2[i];
	return (join);
}

size_t len_str(char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (i);
	while(s[i] != '\0' && s[i] != '\n')
		i++;
	return(i);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_dup_mod(char *s, int idx)
{
	char			*st;
	int				i;

	st = ft_calloc(idx + 2, 1);
	if (!st)
		return (NULL);
	i = 0;
	while (i <= idx)
	{
		st[i] = s[i];
		i++;
	}
	return (st);
}

char	*ft_strdup(char *s)
{
	char			*st;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	st = malloc(sizeof(char) * i + 1);
	if (!st)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	if (nmemb * size > ULONG_MAX)
		return (NULL);
	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	while (i < nmemb * size)
		((char *)a)[i++] = 0;
	return (a);
}

// char	*ft_substr(char *str, unsigned int idx, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	i = -1;
// 	if (idx > len_str(str))
// 	{
// 		sub = malloc(sizeof(char) * 1);
// 		if (sub == NULL)
// 			return (NULL);
// 		*sub = '\0';
// 		return (sub);
// 	}
// 	str += idx;
// 	if (len_str(str) <= len)
// 		sub = malloc(sizeof(char) * len_str(str) + 1);
// 	else
// 		sub = malloc(sizeof(char) * len + 1);
// 	if (sub == NULL)
// 		return (NULL);
// 	while (str[++i] && i < len)
// 		sub[i] = str[i];
// 	sub[i] = '\0';
// 	return (sub);
// }