/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:50:13 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 13:19:51 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_cw(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	ft_len(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static void	*ft_avoid_leak(char **str, int indice)
{
	int	i;

	i = 0;
	while (i < indice)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static char	**ft_do(char const *s, int rows, char c, char **str)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < rows)
	{
		while (*s == c)
			s++;
		len = ft_len(s, c);
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (ft_avoid_leak(str, i));
		j = 0;
		while (j < len)
			str[i][j++] = *s++;
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		rows;

	if (!s)
		return (NULL);
	rows = ft_cw(s, c);
	str = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!str)
		return (NULL);
	str = ft_do(s, rows, c, str);
	return (str);
}
