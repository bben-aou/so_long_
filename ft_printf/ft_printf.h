/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:40:48 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/12 20:19:02 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *f, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putunsigned(unsigned int nbr);
int	ft_hexaup(unsigned int n);
int	ft_hexalow(unsigned int n);
int	ft_check(va_list ap, char *f);
int	ft_check2(va_list ap, char *f);
int	ft_casep(unsigned long long n);

#endif
