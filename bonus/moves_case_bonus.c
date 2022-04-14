/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_case_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:23:55 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 15:36:36 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	case_d_0_and_c(t_bdata *vars)
{
	if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == '0')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_moves)++;
	}
	else if (vars->arr[vars->yplayer][(vars->xpalyer) + 1] == 'C')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) + 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		(vars->number_of_moves)++;
	}
}

void	case_a_0_and_c(t_bdata *vars)
{
	if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == '0')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_moves)++;
	}
	else if (vars->arr[vars->yplayer][(vars->xpalyer) - 1] == 'C')
	{
		vars->arr[vars->yplayer][(vars->xpalyer) - 1] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		(vars->number_of_moves)++;
	}
}

void	case_w_0_and_c(t_bdata *vars)
{
	if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == '0')
	{
		vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_moves)++;
	}
	else if (vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] == 'C')
	{
		vars->arr[(vars->yplayer) - 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		(vars->number_of_moves)++;
	}
}

void	case_s_0_and_c(t_bdata *vars)
{
	if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == '0')
	{
		vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_moves)++;
	}
	else if (vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] == 'C')
	{
		vars->arr[(vars->yplayer) + 1][(vars->xpalyer)] = 'P';
		vars->arr[vars->yplayer][vars->xpalyer] = '0';
		(vars->number_of_collectible)--;
		(vars->number_of_moves)++;
	}
}
