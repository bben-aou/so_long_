/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:19:39 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 13:19:00 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_walls(char **arr, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (arr[i][0] != '1' || arr[i][columns - 1] != '1')
		{
			ft_printf("Error\n Check The walls On Your Map\n");
			exit(1);
		}
		i++;
	}
}

void	check_validation_map(char **arr, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '0' || arr[i][j] == '1'
			|| arr[i][j] == 'C' || arr[i][j] == 'E' || arr[i][j] == 'P')
				j++;
			else
			{
				ft_printf("Error\n incorrect Component On Your Map !!\n");
				exit(1);
			}
		}
		i++;
	}
}

void	check_exist_of_components(char **arr, int rows)
{
	t_var	v;

	v.i = 0;
	v.c = 0;
	v.e = 0;
	v.p = 0;
	while (v.i < rows)
	{
		v.j = 0;
		while (arr[v.i][v.j])
		{
			if (arr[v.i][v.j] == 'C')
				v.c++;
			else if (arr[v.i][v.j] == 'E')
				v.e++;
			else if (arr[v.i][v.j] == 'P')
				v.p++;
			v.j++;
		}
		v.i++;
	}
	if (v.c == 0 || v.p == 0 || v.e == 0)
		message_component();
}

void	check_if_map_rectangular(char **arr, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (ft_strlen2(arr[i]) != columns)
		{
			ft_printf("Error\nThe Map is Not rectangular !!\n");
			exit(1);
		}
		i++;
	}
	if (columns == rows)
	{
		ft_printf("Error\nThe Map is Not rectangular !!\n");
		exit(1);
	}
}

void	check_map(t_data *vars, int rows, int columns)
{
	check_error_walls(vars->arr, rows, columns);
	check_validation_map(vars->arr, rows);
	check_exist_of_components(vars->arr, rows);
	check_if_map_rectangular(vars->arr, rows, columns);
}
