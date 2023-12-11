/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:37:51 by nromito           #+#    #+#             */
/*   Updated: 2023/11/08 17:15:34 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include "ft_printf.h"

//static int count = 0;


int	ft_putnbr(int nb, int count)
{
	//static int count = 0;
	char	digit;
	long	i;
	
	i = (long)nb;
	if (i < 0)
	{
		count += write(1, "-", 1);
		i = -i;
		//*count++;
	}
	digit = 48 + (i % 10);
	if (i >= 10)
		count = ft_putnbr(i / 10, count);
	count += write(1, &digit, 1);
	return (count);
}

// int main()
// {
// 	int count = 0;
// 	int i = ft_putnbr(123456789, count);
// 	printf("\n%d", i);
// }