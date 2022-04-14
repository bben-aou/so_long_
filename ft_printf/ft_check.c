/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:09:19 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 15:28:26 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list ap, char *f)
{
	int	size;

	size = 0;
	size += ft_check2(ap, f);
	if (*f == 'u')
		size += ft_putunsigned(va_arg(ap, int));
	if (*f == 'X')
		size += ft_hexaup(va_arg(ap, int));
	if (*f == 'x')
		size += ft_hexalow(va_arg(ap, int));
	if (*f == 'p')
	{
		size += ft_casep(va_arg(ap, unsigned long));
	}
	return (size);
}
