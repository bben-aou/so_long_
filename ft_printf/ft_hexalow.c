/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:58:35 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 15:09:43 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalow(unsigned int n)
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
		i += ft_hexalow(n / 16);
		i += ft_hexalow(n % 16);
	}
	return (i);
}
