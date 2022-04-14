/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:40:07 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:41:59 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	message_file_b(void)
{
	ft_printf("Error\nCheck your file !!");
	exit(1);
}

void	message_empty_file_b(void)
{
	ft_printf("Error\nMap empty or doesn't exist!!!\n");
	exit(1);
}

void	message_check_map_b(void)
{
	ft_printf("Error\nCheck Your Map !!\n");
	exit (1);
}
