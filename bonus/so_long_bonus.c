/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:46:06 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:36:00 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	key_hook(int key, t_bdata *vars)
{
	t_bimg	imgs;

	if (key == 13)
		move_w_bonus(vars, &imgs);
	if (key == 0)
		move_a_bonus(vars, &imgs);
	if (key == 2)
		move_d_bonus(vars, &imgs);
	if (key == 1)
		move_s_bonus(vars, &imgs);
	if (key == 53)
		cross_bonus(vars);
	vars->pressed_key = key;
	return (0);
}

static void	initialization_mlx_bonus(t_bdata *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

static void	creation_new_window_bonus(t_bdata *vars, t_bimg *imgs)
{
	vars->win_ptr = mlx_new_window
		(vars->mlx_ptr, imgs->img_height,
			imgs->img_width, "So_Long");
	if (vars->win_ptr == NULL)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	vars->number_of_moves = 0;
}

int	check_extension_b(char *str)
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
	t_bdata	bvars;
	t_bimg	bimgs;

	(void)argc;
	bvars.fd = open(argv[1], O_RDONLY);
	if (!(bvars.fd))
		message_error_bonus();
	check_extension_validation_b(argv[1]);
	reading_map_bonus(&bvars);
	get_dimensions_bonus(bvars.arr, &rows, &columns);
	check_map_bonus(&bvars, rows, columns);
	initialization_mlx_bonus(&bvars);
	fill_dimensions_bonus(&bimgs, rows, columns);
	creation_new_window_bonus(&bvars, &bimgs);
	count_number_of_collectible_bonus(&bvars);
	fill_paths_bonus(&bimgs);
	convert_all_assets_of_map_bonus(&bvars, &bimgs);
	mlx_loop_hook(bvars.mlx_ptr, moves_enemy, &bvars);
	print_map_bonus(&bvars, &bimgs);
	mlx_key_hook(bvars.win_ptr, key_hook, &bvars);
	mlx_hook(bvars.win_ptr, 17, 1L << 17, cross_bonus, &bvars);
	mlx_loop(bvars.mlx_ptr);
	free_and_close(&bvars);
}
