/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:27 by nromito           #+#    #+#             */
/*   Updated: 2023/12/21 15:23:18 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
// #include "get_next_line_utils.c"

char	*free_and_null_all(char *buf, char **str)
{
	free (buf);
	return (NULL);
}

size_t	funz_new_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	*create_str(char *str, int fd)
{
	int		char_read;
	char	*buf;
	char	*raw_str;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	if (str && str[0] == '\n')
		str++;
	while (1)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			if (str == NULL)
				return (NULL);
				//free (raw_str);
			raw_str = str_dup_mod(str, ft_strlen(str));
			break ;
		}
		//free (raw_str);
		raw_str = str_join_mod(str, buf);
		str = raw_str;
		if (funz_new_line(str))
			break ;
	}
	free_and_null_all (buf, &str);
	return (raw_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*new_line;
	char		*raw_str;
	int			idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	raw_str = create_str(str, fd);
	if (!raw_str[0] && !str[0])
	{
		// free_and_null_all(raw_str, &str);
		free (str);
		str = NULL;
		return(NULL);
	}
	idx = find_newline(raw_str);
	new_line = str_dup_mod(raw_str, idx);
	free(str);
	str = ft_strdup(raw_str + len_str(new_line));
	if (!*new_line)
	{
		if (str != NULL)
			free(str);
		str = NULL;
	}
	// str = tmp;
	free(raw_str);
	return (new_line);
}
	// ritorna la prima parte di stringa e libera str da quella memoria,
	// salva in una variabile temporanea la seconda parte di stringa dopo \n,  
	
int	main()
{
	char *risultato;
	int	i = 0;
	int fd = open("text.txt", O_RDWR);
	while (i < 11)
	{
		risultato = get_next_line(fd);
		printf("%s", risultato);
		free(risultato);
		i++;	
	}
	// risultato = get_next_line(fd);
	// printf("%s", risultato);
	// free (risultato);

	// risultato = get_next_line(fd);
	// printf("%s", risultato);
	// free (risultato);

	// risultato = get_next_line(fd);
	// printf("%s", risultato);
	// free (risultato);
		
	close(fd);
	return (0);
}
