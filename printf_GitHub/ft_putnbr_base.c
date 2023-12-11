/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:59:59 by nromito           #+#    #+#             */
/*   Updated: 2023/11/08 13:53:16 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_cond1(char *base)
{
	int	len;

	len = 0;
	while (base[len] != 0)
	{
		if (base[len] == 43 || base[len] == 45)
		{
			return ('0');
		}
		len++;
	}
	return ('1');
}

char	ft_cond2(char *base)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (base[i] != 0)
	{
		while (base[len] != 0)
		{
			if ((base[len] == base[i]) && (len != i))
			{
				return ('0');
			}
			else
				len++;
		}
		len = 0;
		i++;
	}
	return ('1');
}

long	ft_neg(long nbrl)
{
	if (nbrl < 0)
	{
		nbrl = -nbrl;
		write(1, "-", 1);
		return (nbrl);
	}
	return (nbrl);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		i;
	long	nbrl;

	i = 0;
	nbrl = nbr;
	if (ft_cond1(base) == '0' || ft_cond2(base) == '0')
		return (0);
	len = 0;
	nbrl = ft_neg(nbrl);
	if (!(base[len] == 0 || base[len] == 1))
	{
		while (base[len] != '\0')
			len++;
		if (len < 2)
			return (0);
		if (nbrl >= len)
			ft_putnbr_base((nbrl / len), base);
		write(1, &base[nbrl % len], 1);
	}
	return (len);
}
