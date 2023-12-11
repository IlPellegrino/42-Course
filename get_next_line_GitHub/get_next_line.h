/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:35 by nromito           #+#    #+#             */
/*   Updated: 2023/12/11 08:12:14 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*create_str(char *str, int fd);
int		find_newline(const char *str, int c);
char	*str_join_mod(const char *s1, const char *s2);
size_t	len_str(const char *s);
char	*str_dup_mod(const char *s, int idx);