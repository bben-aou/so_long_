/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:48:48 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:42:09 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	convert_all_assets_of_map_bonus(t_bdata *vars, t_bimg *imgs)
{
	imgs->img = mlx_xpm_file_to_image
		(vars->mlx_ptr, imgs->relative_path,
			&(imgs->img_height), &(imgs->img_width));
	imgs->img_walls = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_wall, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_door = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_door, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_collectible = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_collectible, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_player = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_player, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_playerleft = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_leftplayer, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_police_left = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_policeleft, &(imgs->img_wh), &(imgs->img_ww));
	imgs->img_police_right = mlx_xpm_file_to_image(vars->mlx_ptr,
			imgs->relative_path_policeright, &(imgs->img_wh), &(imgs->img_ww));
}

void	count_number_of_collectible_bonus(t_bdata *vars)
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

void	reading_map_bonus(t_bdata *vars)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(vars->fd);
	if (!str)
		message_empty_file_b();
	if (str[0] == '\n')
		message_check_map_b();
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			message_check_map_b();
		i++;
	}
	vars->arr = ft_split(str, '\n');
	free(str);
}

void	print_map_bonus(t_bdata *vars, t_bimg *imgs)
{
	print_background_bonus(vars, imgs->img);
	print_elemets_of_map_bonus(vars, imgs);
	mlx_string_put
		(vars->mlx_ptr, vars->win_ptr, 0, 1,
			0x0000ff, "the current number of movements :");
}

void	check_extension_validation_b(char *str)
{
	if (!check_extension_b(str))
		message_file_b();
}
