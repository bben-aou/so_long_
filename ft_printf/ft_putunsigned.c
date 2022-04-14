/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:05:46 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 15:45:28 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	char	c;
	int		i;

	i = 0;
	if (nbr <= 9)
	{
		c = nbr + 48;
		i += write(1, &c, 1);
	}
	if (nbr > 9)
	{
		i += ft_putunsigned(nbr / 10);
		i += ft_putunsigned(nbr % 10);
	}
	return (i);
}
