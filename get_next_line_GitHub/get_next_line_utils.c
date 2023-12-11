/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:38 by nromito           #+#    #+#             */
/*   Updated: 2023/12/11 11:16:46 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(const char *s, int c)
{
	int				i;
	unsigned char	j;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (++i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (0);
}

char	*str_join_mod(const char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

		len1 = len_str(s1);
		len2 = len_str(s2);
		join = malloc(sizeof(char) * (len1 + len2 + 1));
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
		join[len1] = '\0';
		return (join);
}

size_t len_str(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (i);
	while(s[i])
		i++;
	return(i);
}

char	*str_dup_mod(const char *s, int idx)
{
	char			*st;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	st = malloc(sizeof(char) * idx + 2);
	if (!st)
		return (NULL);
	i = 0;
	while (i <= idx)
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	*ft_substr(char *str, unsigned int idx, size_t len)
{
	char	*sub;
	size_t	i;

	i = -1;
	if (idx > len_str(str))
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	str += idx;
	if (len_str(str) <= len)
		sub = malloc(sizeof(char) * len_str(str) + 1);
	else
		sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (NULL);
	while (str[++i] && i < len)
		sub[i] = str[i];
	sub[i] = '\0';
	return (sub);
}