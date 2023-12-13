/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:27 by nromito           #+#    #+#             */
/*   Updated: 2023/12/13 18:23:40 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// #include "get_next_line_utils.c"

void	*create_str(char *str, int fd)
{
	int		char_read;
	char	*buf;
	char	*raw_str;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return NULL;
	if (str && str[0] == '\n')
		str++;
	while (1)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return NULL;
		}
		raw_str = str_join_mod(str, buf);
		str = raw_str;
		if (find_newline(str, '\n'))
			break ;
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
	raw_str = create_str(str, fd);
	if (raw_str == NULL)
		return NULL;
	idx = find_newline(raw_str, '\n');
	new_line = str_dup_mod(raw_str, idx - 1);
	str = ft_strdup(raw_str + len_str(new_line));
	free(raw_str);
	return (new_line);

}
	// ritorna la prima parte di stringa e libera str da quella memoria,
	// salva in una variabile temporanea la seconda parte di stringa dopo \n,  
	
int	main()
{
	char *risultato;
	
	int fd = open("text.txt", O_RDWR);
	
	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);
	
	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);

	risultato = get_next_line(fd);
	printf("%s", risultato);
	free(risultato);
		
	close(fd);
	return (0);
}