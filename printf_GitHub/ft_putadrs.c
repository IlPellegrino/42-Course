/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:22:35 by nromito           #+#    #+#             */
/*   Updated: 2023/11/07 16:26:31 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadrs(void *nb)
{
	char	*digit;
	long	i;
	int		count;

	count = 0;
	i = (long)nb;
	ft_putstr("0x");
	digit = malloc(sizeof(char));
	digit = 48 + ((void *)(i % 16));
	if (i >= 16)
		count += ft_putadrs((void *)(i / 16));
	ft_putstr(digit);
	return (count);
}
