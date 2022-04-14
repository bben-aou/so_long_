/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:51:54 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 17:17:12 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	strlen_bonus(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	cross_bonus(t_bdata *vars)
{
	write(1, "Game Over !\n", 12);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(1);
}

int	ft_strncmp1(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n && ((s2[i] != '\0' && s1[i] == '\0')
			|| (s1[i] != '\0' && s2[i] == '\0')))
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	free_and_close(t_bdata *vars)
{
	free(vars->ptr);
	close(vars->fd);
}
