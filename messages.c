/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:58:05 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:28:27 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_error(void)
{
	perror("Error ");
	exit(1);
}

void	message_component(void)
{
	ft_printf("Error\n Check The Components On Your Map\n");
	exit(1);
}

void	message_file(void)
{
	ft_printf("Error\nCheck your file !!");
	exit(1);
}

void	message_empty_file(void)
{
	ft_printf("Error\nMap empty or doesn't exist!!!\n");
	exit(1);
}

void	message_check_map(void)
{
	ft_printf("Error\nCheck Your Map !!\n");
	exit (1);
}
