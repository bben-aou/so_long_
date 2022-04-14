/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:58:20 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:41:49 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	message_error_bonus(void)
{
	perror("Error ");
	exit(1);
}

void	message_component_bonus(void)
{
	ft_printf("Error\n Check The Components On Your Map\n");
	exit(1);
}

void	desplay_number_of_movement_with_message(t_bdata *vars)
{
	mlx_string_put
		(vars->mlx_ptr, vars->win_ptr, 0, 1,
			0xff0000, "the current number of movements: ");
	mlx_string_put
		(vars->mlx_ptr, vars->win_ptr, 330, 1,
			0xffd700, ft_itoa(vars->number_of_moves, vars));
}
