/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:40:16 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 17:27:02 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_dimensions_bonus(char **arr, int *rows, int *columns)
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

void	get_position_of_player_bonus(t_bdata *vars)
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

void	get_position_of_enemy_bonus(t_bdata *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			if (vars->arr[i][j] == 'A')
			{
				vars->yenemy = i;
				vars->xenemy = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_paths_bonus(t_bimg *imgs)
{
	imgs->relative_path = "./imgs/back65.xpm";
	imgs->relative_path_wall = "./imgs/wall65.xpm";
	imgs->relative_path_door = "./imgs/hole3.xpm";
	imgs->relative_path_collectible = "./imgs/collectible65.xpm";
	imgs->relative_path_player = "./imgs/playerRight.xpm";
	imgs->relative_path_leftplayer = "./imgs/playerLeft.xpm";
	imgs->relative_path_policeleft = "./imgs/PoliceLeft.xpm";
	imgs->relative_path_policeright = "./imgs/PoliceRight.xpm";
}

void	fill_dimensions_bonus(t_bimg *imgs, int rows, int columns)
{
	imgs->img_width = rows * 65;
	imgs->img_height = columns * 65;
	imgs->img_ww = 65;
	imgs->img_wh = 65;
}
