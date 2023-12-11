/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:39:46 by nromito           #+#    #+#             */
/*   Updated: 2023/11/08 17:10:48 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int nb, int count)
{
	char	digit;
	
	digit = 48 + (nb % 10);
	if (nb >= 10)
		count = ft_putuns(nb / 10, count);
	count += write(1, &digit, 1);
	return (count);
}
