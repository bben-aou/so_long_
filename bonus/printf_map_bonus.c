/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:39:34 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 17:27:14 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_background_bonus(t_bdata *vars, void *img)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			mlx_put_image_to_window
				(vars->mlx_ptr, vars->win_ptr,
					img, j * 65, i * 65);
			j++;
		}
		i++;
	}
}

void	print_em_cases_bonus(t_bdata *vars, t_bimg *imgs, int i, int j)
{
	if (vars->arr[i][j] == '1')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_walls, j * 65, i * 65);
	else if (vars->arr[i][j] == '0')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img, j * 65, i * 65);
	else if (vars->arr[i][j] == 'E')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_door, j * 65, i * 65);
	else if (vars->arr[i][j] == 'C')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_collectible, j * 65, i * 65);
	else if (vars->arr[i][j] == 'P')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_player, j * 65, i * 65);
	else if (vars->arr[i][j] == 'A')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_police_right, j * 65, i * 65);
}

void	print_elemets_of_map_bonus(t_bdata *vars, t_bimg *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			print_em_cases_bonus(vars, imgs, i, j);
			j++;
		}
		i++;
	}
}

void	check_map_bonus(t_bdata *vars, int rows, int columns)
{
	check_error_walls_bonus(vars->arr, rows, columns);
	check_validation_map_bonus(vars->arr, rows);
	check_exist_of_components_bonus(vars->arr, rows);
	check_if_map_rectangular_bonus(vars->arr, rows, columns);
}
