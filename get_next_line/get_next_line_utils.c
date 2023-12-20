/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:38 by nromito           #+#    #+#             */
/*   Updated: 2023/12/20 19:31:54 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if(s[i] == '\n')
		i++;
	return (i);
}

char	*str_join_mod(char *str, char *buf)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(str);
	len2 = ft_strlen(buf);
	join = ft_calloc(len1 + len2 + 1, 1);
	if (join == NULL)
		return (NULL);
	i = -1;
	if (str == NULL)
	{
		while (buf[++i])
			join[len1++] = buf[i];
		return (join);
	}
	while (str[++i])
		join[i] = str[i];
	i = -1;
	while (buf[++i])
		join[len1++] = buf[i];
	// str = NULL;
	return (join);
}

size_t len_str(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
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

char	*str_dup_mod(char *raw_str, int idx)
{
	char			*st;
	int				i;

	st = ft_calloc(idx + 1, sizeof(char));
	if (!st)
		return (NULL);
	i = 0;
	while (i < idx)
	{
		st[i] = raw_str[i];
		i++;
	}
	return (st);
}

char	*ft_strdup(char *raw_str)
{
	char			*st;
	unsigned int	i;

	st = ft_calloc(ft_strlen(raw_str) + 1, 1);
	if (!st)
		return (NULL);
	i = 0;
	while (raw_str[i] != '\0')
	{
		st[i] = raw_str[i];
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