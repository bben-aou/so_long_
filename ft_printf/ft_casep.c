/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:35:49 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 17:29:32 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalong(unsigned long long n)
{
	char	*base;
	char	c;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
	{
		c = base[n];
		i += write (1, &c, 1);
	}
	else
	{
		i += ft_hexalong(n / 16);
		i += ft_hexalong(n % 16);
	}
	return (i);
}

int	ft_casep(unsigned long long n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += ft_hexalong(n);
	return (i);
}
