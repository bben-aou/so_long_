/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:02:57 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:27:31 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	void	*relative_path;
	int		img_width;
	int		img_height;
	void	*img_walls;
	void	*relative_path_wall;
	void	*img_door;
	void	*relative_path_door;
	void	*img_collectible;
	void	*relative_path_collectible;
	void	*img_player;
	void	*relative_path_player;
	void	*relative_path_leftplayer;
	void	*img_pl;
	void	*relative_path_policeleft;
	void	*img_police_left;
	void	*relative_path_policeright;
	void	*img_police_right;
	int		img_ww;
	int		img_wh;	
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	int		xpalyer;
	int		yplayer;
	char	**arr;
	int		number_of_collectible;
	int		number_of_moves;
	char	key;
}	t_data;

typedef struct s_components
{
	int	i;
	int	j;
	int	c;
	int	p;
	int	e;
}	t_var;

int		ft_strlen2(const char *str);
void	message_error(void);
void	check_error_walls(char **arr, int rows, int columns);
void	check_validation_map(char **arr, int rows);
void	check_exist_of_components(char **arr, int rows);
void	check_if_map_rectangular(char **arr, int rows, int columns);
void	get_dimensions(char **arr, int *rows, int *columns);
void	get_position_of_player(t_data *vars);
int		cross(t_data *vars);
void	reprint_map(t_data *vars, t_img *imgs, char key);
void	move_d(t_data *vars, t_img *imgs);
void	move_a(t_data *vars, t_img *imgs);
void	move_w(t_data *vars, t_img *imgs);
void	move_s(t_data *vars, t_img *imgs);
int		key_hook(int key, t_data *vars);
void	print_background(t_data *vars, void *img);
void	fill_paths(t_img *imgs);
void	fill_dimensions(t_img *imgs, int rows, int columns);
void	convert_all_assets_of_map(t_data *vars, t_img *imgs);
void	print_elemets_of_map(t_data *vars, t_img *imgs);
void	count_number_of_collectible(t_data *vars);
void	reading_map(t_data *vars);
void	initialization_mlx(t_data *vars);
void	creation_new_window(t_data *vars, t_img *imgs);
void	check_map(t_data *vars, int rows, int columns);
void	print_map(t_data *vars, t_img *imgs);
void	reprint_map_part_1(t_data *vars, t_img *imgs);
void	reprint_map_part_2(t_data *vars, t_img *imgs, int i, int j);
void	message_component(void);
void	avoid_leaks(t_data *vars);
int		ft_strncmp1(char *s1, char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	display_moves(t_data *vars);
void	reprint_map_part_3(t_data *vars, t_img *imgs, int i, int j);
void	print_elemets_of_map_1(t_data *vars, t_img *imgs, int i, int j);
int		check_extension(char *str);
void	message_file(void);
void	check_extension_validation(char *str);
void	message_empty_file(void);
void	message_check_map(void);

#endif