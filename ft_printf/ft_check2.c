/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:12:03 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 14:55:58 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check2(va_list ap, char *f)
{
	int	size;

	size = 0;
	if (*f == 'c')
	{
		size += ft_putchar((char)va_arg(ap, int));
	}
	if (*f == 's')
		size += ft_putstr(va_arg(ap, char *));
	if (*f == 'd' || *f == 'i')
		size += ft_putnbr(va_arg(ap, int));
	if (*f == '%')
	{
		size += ft_putchar('%');
	}
	return (size);
}
