/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:06:33 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 17:27:36 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reprint_map_part_2_bonus(t_bdata *vars, t_bimg *imgs, int i, int j)
{
	if (vars->arr[i][j] == '1')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_walls, j * 65, i * 65);
	else if (vars->arr[i][j] == '0')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img, j * 65, i * 65);
	else if (vars->arr[i][j] == 'E')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_door, j * 65, i * 65);
	else if (vars->arr[i][j] == 'C')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_collectible, j * 65, i * 65);
	else if (vars->arr[i][j] == 'A')
	{
		if (vars->position_of_enemy == 'r')
			mlx_put_image_to_window
				(vars->mlx_ptr, vars->win_ptr,
					imgs->img_police_right, j * 65, i * 65);
		if (vars->position_of_enemy == 'l')
			mlx_put_image_to_window
				(vars->mlx_ptr, vars->win_ptr,
					imgs->img_police_left, j * 65, i * 65);
	}
}

void	reprint_mp1_cases_bonus(t_bdata *vars, t_bimg *imgs, int i, int j)
{
	if (vars->key == 'D')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_player, j * 65, i * 65);
	else if (vars->key == 'A')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_playerleft, j * 65, i * 65);
	else
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr,
				imgs->img_player, j * 65, i * 65);
}

void	reprint_map_part_1_bonus(t_bdata *vars, t_bimg *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			reprint_map_part_2_bonus(vars, imgs, i, j);
			if (vars->arr[i][j] == 'P')
				reprint_mp1_cases_bonus(vars, imgs, i, j);
			j++;
		}
		i++;
	}
}

void	reprint_map_bonus(t_bdata *vars, t_bimg *imgs, char key)
{
	vars->key = key;
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	fill_paths_bonus(imgs);
	convert_all_assets_of_map_bonus(vars, imgs);
	print_background_bonus(vars, imgs->img);
	reprint_map_part_1_bonus(vars, imgs);
	desplay_number_of_movement_with_message(vars);
}
