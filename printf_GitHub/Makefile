# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromito <nromito@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:28:39 by nromito           #+#    #+#              #
#    Updated: 2023/11/07 20:49:50 by nromito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c ft_putadrs.c ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c ft_putuns.c ft_strlen.c ft_strcpy.c ft_itoa.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rc ${NAME} ${MANDATORY_OBJS}
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${MANDATORY_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all