/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:11:18 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 16:51:27 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_bonus(t_bdata *vars)
{
	t_bimg	imgs;

	if (vars->pressed_key == 13)
		reprint_map_bonus(vars, &imgs, 'D');
	if (vars->pressed_key == 0)
		reprint_map_bonus(vars, &imgs, 'A');
	if (vars->pressed_key == 2)
		reprint_map_bonus(vars, &imgs, 'D');
	if (vars->pressed_key == 1)
		reprint_map_bonus(vars, &imgs, 'D');
	if (vars->pressed_key == 53)
		cross_bonus(vars);
}

void	moves_enemy_left(t_bdata *vars)
{
	if (vars->arr[vars->yenemy][(vars->xenemy) - 1] == '0')
	{
		vars->arr[vars->yenemy][vars->xenemy - 1] = 'A';
		vars->arr[vars->yenemy][vars->xenemy] = '0';
	}
	if (vars->arr[vars->yenemy][(vars->xenemy) - 1] == 'P')
	{
		ft_printf("Game Over !!\n");
		exit(0);
	}
	vars->position_of_enemy = 'l';
	key_bonus(vars);
}

int	moves_enemy(t_bdata *vars)
{
	get_position_of_enemy_bonus(vars);
	vars->count++;
	if (vars->count == 50)
	{
		if (vars->arr[vars->yenemy][(vars->xenemy) + 1] == '0')
		{
			vars->position_of_enemy = 'r';
			vars->arr[vars->yenemy][(vars->xenemy) + 1] = 'A';
			vars->arr[vars->yenemy][vars->xenemy] = '0';
		}
		if (vars->arr[vars->yenemy][(vars->xenemy) + 1] == 'P')
		{
			ft_printf("Game Over !!\n");
			exit(0);
		}
		if (vars->arr[vars->yenemy][(vars->xenemy) + 1] == '1'
			|| vars->arr[vars->yenemy][(vars->xenemy) + 1] == 'C'
				|| vars->arr[vars->yenemy][(vars->xenemy) + 1] == 'E')
			moves_enemy_left(vars);
	vars->count = 0;
	}
	key_bonus(vars);
	return (0);
}
