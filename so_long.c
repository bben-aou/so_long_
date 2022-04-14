/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:02:54 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:24:26 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *vars)
{
	t_img	imgs;

	if (key == 13)
		move_w(vars, &imgs);
	if (key == 0)
		move_a(vars, &imgs);
	if (key == 2)
		move_d(vars, &imgs);
	if (key == 1)
		move_s(vars, &imgs);
	if (key == 53)
		cross(vars);
	return (0);
}

void	initialization_mlx(t_data *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

void	creation_new_window(t_data *vars, t_img *imgs)
{
	vars->win_ptr = mlx_new_window
		(vars->mlx_ptr, imgs->img_height, imgs->img_width, "So_Long");
	if (vars->win_ptr == NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	vars->number_of_moves = 0;
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 4] == '.')
		if (str[len - 3] == 'b')
			if (str[len - 2] == 'e')
				if (str[len - 1] == 'r')
					return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		rows;
	int		columns;
	t_data	vars;
	t_img	imgs;

	(void)argc;
	vars.fd = open(argv[1], O_RDONLY);
	if (!(vars.fd))
		message_error();
	check_extension_validation(argv[1]);
	reading_map(&vars);
	get_dimensions(vars.arr, &rows, &columns);
	check_map(&vars, rows, columns);
	initialization_mlx(&vars);
	fill_dimensions(&imgs, rows, columns);
	creation_new_window(&vars, &imgs);
	count_number_of_collectible(&vars);
	fill_paths(&imgs);
	convert_all_assets_of_map(&vars, &imgs);
	print_map(&vars, &imgs);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 1L << 17, cross, &vars);
	mlx_loop(vars.mlx_ptr);
	close(vars.fd);
}
