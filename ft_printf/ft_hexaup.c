/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printHex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:49:14 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 14:59:01 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaup(unsigned int n)
{
	char	*base;
	char	c;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (n < 0)
	{
		i += write (1, "-", 1);
		n = -n;
	}
	if (n < 16)
	{
		c = base[n];
		i += write (1, &c, 1);
	}
	else
	{
		i += ft_hexaup(n / 16);
		i += ft_hexaup(n % 16);
	}
	return (i);
}
