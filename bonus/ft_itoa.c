/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:39:40 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 15:08:53 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n, t_bdata *vars)
{
	int	i;

	i = ft_len(n);
	vars->ptr = malloc(sizeof(char) * (i + 1));
	if (!vars->ptr)
		return (NULL);
	vars->ptr[i--] = '\0';
	if (n == 0)
	{
		vars->ptr[0] = '0';
		return (vars->ptr);
	}
	if (n < 0)
		vars->ptr[0] = '-';
	while (n != 0)
	{
		if (vars->ptr[0] == '-')
			vars->ptr[i--] = '0' + -(n % 10);
		else
			vars->ptr[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (vars->ptr);
}
