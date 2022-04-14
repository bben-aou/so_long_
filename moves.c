/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:22:02 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 14:03:46 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_data *vars, t_img *imgs)
{
	get_position_of_player(vars);
	if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == '0')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		display_moves(vars);
	}
	else if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == 'C')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		display_moves(vars);
	}
	if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross(vars);
			display_moves(vars);
		}
	}
	reprint_map(vars, imgs, 'D');
}

void	move_a(t_data *vars, t_img *imgs)
{
	get_position_of_player(vars);
	if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == '0')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		display_moves(vars);
	}
	else if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == 'C')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		display_moves(vars);
	}
	if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross(vars);
			display_moves(vars);
		}
	}
	reprint_map(vars, imgs, 'A');
}

void	move_w(t_data *vars, t_img *imgs)
{
	get_position_of_player(vars);
	if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == '0')
	{
		vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		display_moves(vars);
	}
	else if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == 'C')
	{
		vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		display_moves(vars);
	}
	if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross(vars);
			display_moves(vars);
		}
	}
	reprint_map(vars, imgs, 'W');
}

void	move_s(t_data *vars, t_img *imgs)
{
	get_position_of_player(vars);
	if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == '0')
	{
		vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		display_moves(vars);
	}
	else if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == 'C')
	{
		vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		display_moves(vars);
	}
	if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross(vars);
			display_moves(vars);
		}
	}
	reprint_map(vars, imgs, 'S');
}
