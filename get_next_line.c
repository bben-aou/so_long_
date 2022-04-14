/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:57:44 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 13:35:06 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_checkline(char *svar)
{
	int		i;
	char	*ar;

	i = 0;
	if (!svar[i])
		return (NULL);
	while (svar[i])
		i++;
	ar = (char *)malloc(sizeof(char) * (i + 2));
	if (!ar)
		return (NULL);
	i = 0;
	while (svar[i])
	{
		ar[i] = svar[i];
		i++;
	}
	ar[i] = '\0';
	return (ar);
}

char	*ft_nextline(char *svar)
{
	int		i;
	int		c;
	char	*temp;

	i = 0;
	while (svar[i])
		i++;
	if (!svar[i])
	{
		free(svar);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(svar) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	c = 0;
	while (svar[i])
		temp[c++] = svar[i++];
	temp[c] = '\0';
	free(svar);
	return (temp);
}

char	*ft_fill_line(int fd, char *svar)
{
	char	*str;
	int		b;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	b = 1;
	while (b != 0)
	{
		b = read(fd, str, BUFFER_SIZE);
		if (b == -1)
		{
			free(str);
			return (NULL);
		}
		str[b] = '\0';
		svar = ft_strjoin(svar, str);
	}
	free(str);
	return (svar);
}

char	*get_next_line(int fd)
{
	char		*checkedline;
	static char	*svar;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	svar = ft_fill_line(fd, svar);
	if (!svar)
		return (NULL);
	checkedline = ft_checkline(svar);
	svar = ft_nextline(svar);
	return (checkedline);
}
