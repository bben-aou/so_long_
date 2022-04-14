/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:23:43 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 14:39:55 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_background(t_data *vars, void *img)
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
			(vars->mlx_ptr, vars->win_ptr, img, j * 65, i * 65);
			j++;
		}
		i++;
	}
}

void	print_elemets_of_map_1(t_data *vars, t_img *imgs, int i, int j)
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
	else if (vars->arr[i][j] == 'P')
		mlx_put_image_to_window
		(vars->mlx_ptr, vars->win_ptr, imgs->img_player, j * 65, i * 65);
}

void	print_elemets_of_map(t_data *vars, t_img *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			print_elemets_of_map_1(vars, imgs, i, j);
			j++;
		}
		i++;
	}
}
