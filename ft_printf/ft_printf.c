/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:31:27 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 20:30:46 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	char	*ptr;
	int		size;

	size = 0;
	va_start (ap, f);
	ptr = (char *)f;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			size += ft_check(ap, ptr);
			if (*(ptr) == '\0')
				break ;
		}
		else
		{
			size += ft_putchar(*ptr);
		}
		ptr++;
	}
	va_end(ap);
	return (size);
}
