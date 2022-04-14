/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:29:12 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:28:56 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_all_assets_of_map(t_data *vars, t_img *imgs)
{
	imgs->img = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path,
			&(imgs->img_height), &(imgs->img_width));
	imgs->img_walls = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path_wall,
			&(imgs->img_wh), &(imgs->img_ww));
	imgs->img_door = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path_door,
			&(imgs->img_wh), &(imgs->img_ww));
	imgs->img_collectible = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path_collectible,
			&(imgs->img_wh), &(imgs->img_ww));
	imgs->img_player = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path_player,
			&(imgs->img_wh), &(imgs->img_ww));
	imgs->img_pl = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path_leftplayer,
			&(imgs->img_wh), &(imgs->img_ww));
}

void	count_number_of_collectible(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->number_of_collectible = 0;
	while (vars->arr[i])
	{
		j = 0;
		while (vars->arr[i][j])
		{
			if (vars->arr[i][j] == 'C')
				(vars->number_of_collectible)++;
			j++;
		}
		i++;
	}
}

void	reading_map(t_data *vars)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(vars->fd);
	if (!str)
		message_empty_file();
	if (str[0] == '\n')
		message_check_map();
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			message_check_map();
		i++;
	}
	vars->arr = ft_split(str, '\n');
	free(str);
}

void	print_map(t_data *vars, t_img *imgs)
{
	print_background(vars, imgs->img);
	print_elemets_of_map(vars, imgs);
}

void	check_extension_validation(char *str)
{
	if (!check_extension(str))
		message_file();
}
