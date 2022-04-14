/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:39:22 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 14:40:24 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reprint_map_part_2(t_data *vars, t_img *imgs, int i, int j)
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
		(vars->mlx_ptr, vars->win_ptr, imgs->img_collectible, j * 65, i * 65);
}

void	reprint_map_part_3(t_data *vars, t_img *imgs, int i, int j)
{
	if (vars->arr[i][j] == 'P')
	{
		if (vars->key == 'D')
			mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_player, j * 65, i * 65);
		else if (vars->key == 'A')
			mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_pl, j * 65, i * 65);
		else
			mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, imgs->img_player, j * 65, i * 65);
	}	
}

void	reprint_map_part_1(t_data *vars, t_img *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			reprint_map_part_2(vars, imgs, i, j);
			reprint_map_part_3(vars, imgs, i, j);
			j++;
		}
		i++;
	}
}

void	reprint_map(t_data *vars, t_img *imgs, char key)
{
	vars->key = key;
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	fill_paths(imgs);
	convert_all_assets_of_map(vars, imgs);
	print_background(vars, imgs->img);
	reprint_map_part_1(vars, imgs);
}
