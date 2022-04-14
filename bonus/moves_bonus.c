/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:51:42 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 15:37:00 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_d_bonus(t_bdata *vars, t_bimg *imgs)
{
	get_position_of_player_bonus(vars);
	case_d_0_and_c(vars);
	if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross_bonus(vars);
			(vars->number_of_moves)++;
		}
	}
	if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == 'A')
	{
		ft_printf("Game Over !!\n");
		exit(0);
	}
	reprint_map_bonus(vars, imgs, 'D');
}

void	move_a_bonus(t_bdata *vars, t_bimg *imgs)
{
	get_position_of_player_bonus(vars);
	case_a_0_and_c(vars);
	if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross_bonus(vars);
			(vars->number_of_moves)++;
		}
	}
	if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == 'A')
	{
		ft_printf("Game Over !!\n");
		exit(0);
	}
	reprint_map_bonus(vars, imgs, 'A');
}

void	move_w_bonus(t_bdata *vars, t_bimg *imgs)
{
	get_position_of_player_bonus(vars);
	case_w_0_and_c(vars);
	if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross_bonus(vars);
			(vars->number_of_moves)++;
		}
	}
	if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == 'A')
	{
		ft_printf("Game Over !!\n");
		exit(0);
	}
	reprint_map_bonus(vars, imgs, 'W');
}

void	move_s_bonus(t_bdata *vars, t_bimg *imgs)
{
	get_position_of_player_bonus(vars);
	case_s_0_and_c(vars);
	if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == 'E')
	{
		if ((vars->number_of_collectible) == 0)
		{
			vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
			vars->arr[vars->yplayer][vars->xpalyer] = '0';
			cross_bonus(vars);
			(vars->number_of_moves)++;
		}
	}
	if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == 'A')
	{
		ft_printf("Game Over !!\n");
		exit(0);
	}
	reprint_map_bonus(vars, imgs, 'S');
}
