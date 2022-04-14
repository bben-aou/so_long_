/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:32:11 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 15:08:21 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_error_walls_bonus(char **arr, int rows, int columns)
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

void	check_validation_map_bonus(char **arr, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '0' || arr[i][j] == '1' || arr[i][j] == 'C'
				|| arr[i][j] == 'E' || arr[i][j] == 'P' || arr[i][j] == 'A')
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

void	init_struct_components(t_bvar *v)
{
	v->i = 0;
	v->c = 0;
	v->e = 0;
	v->p = 0;
	v->a = 0;
}

void	check_exist_of_components_bonus(char **arr, int rows)
{
	t_bvar	v;

	init_struct_components(&v);
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
			else if (arr[v.i][v.j] == 'A')
				v.a++;
			v.j++;
		}
		v.i++;
	}
	if (v.c == 0 || v.p == 0 || v.e == 0 || v.a == 0)
		message_component_bonus();
}

void	check_if_map_rectangular_bonus(char **arr, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (strlen_bonus(arr[i]) != columns)
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
