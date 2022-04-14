/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:23:48 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 17:33:16 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_dimensions(char **arr, int *rows, int *columns)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*rows = i;
	i = 0;
	while (arr[0][i])
		i++;
	*columns = i;
}

void	get_position_of_player(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			if (vars->arr[i][j] == 'P')
			{
				vars->yplayer = i;
				vars->xpalyer = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_paths(t_img *imgs)
{
	imgs->relative_path = "./imgs/back65.xpm";
	imgs->relative_path_wall = "./imgs/wall65.xpm";
	imgs->relative_path_door = "./imgs/hole3.xpm";
	imgs->relative_path_collectible = "./imgs/collectible65.xpm";
	imgs->relative_path_player = "./imgs/playerRight.xpm";
	imgs->relative_path_leftplayer = "./imgs/playerLeft.xpm";
}

void	fill_dimensions(t_img *imgs, int rows, int columns)
{
	imgs->img_width = rows * 65;
	imgs->img_height = columns * 65;
	imgs->img_ww = 65;
	imgs->img_wh = 65;
}
