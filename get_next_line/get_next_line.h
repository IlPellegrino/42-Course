/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:35 by nromito           #+#    #+#             */
/*   Updated: 2023/12/13 17:14:18 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd);
void	*create_str(char *str, int fd);
int		find_newline(char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*str_join_mod(char *s1, char *s2);
size_t	len_str(char *s);
char	*str_dup_mod(char *s, int idx);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);