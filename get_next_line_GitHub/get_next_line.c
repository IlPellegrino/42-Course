/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:27 by nromito           #+#    #+#             */
/*   Updated: 2023/12/11 11:19:18 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
// #include "get_next_line_utils.c"

void	*create_str(char *str, int fd)
{
	int		char_read;
	char	*buf;
	char	*raw_str;

	while (!find_newline(str, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return NULL;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read )
		{
			free(buf);
			return NULL;
		}
		buf[char_read] = '\0';
		raw_str = str_join_mod(str, buf);
		str = raw_str;
	}
	free(buf);
	return (raw_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*new_line;
	char		*raw_str;
	int			idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
		raw_str = create_str(str, fd);   //"1234\n6\n8\nn\"
		if (raw_str == NULL)
			return NULL;
	// ritorna la prima parte di stringa e libera str da quella memoria,
	// salva in una variabile temporanea la seconda parte di stringa dopo \n,  
		idx = find_newline(raw_str, '\n');
		new_line = str_dup_mod(raw_str, idx - 1); //(char &str_grezza[0], int idx_nl);
		str = str_dup_mod(&raw_str[idx], len_str(raw_str));
	return (new_line);
	
}

int	main()
{
	char *risultato;
	
	int fd = open("text.txt", O_RDWR);
	
	risultato = get_next_line(fd);
	printf("%s", risultato);
	close(fd);
	return (0);
}