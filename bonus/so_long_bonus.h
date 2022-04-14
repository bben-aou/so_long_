/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:46:51 by bben-aou          #+#    #+#             */
/*   Updated: 2022/04/13 22:36:22 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_bimg
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
	void	*img_playerleft;
	void	*relative_path_policeleft;
	void	*img_police_left;
	void	*relative_path_policeright;
	void	*img_police_right;
	int		img_ww;
	int		img_wh;	
}	t_bimg;

typedef struct s_bdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	int		xpalyer;
	int		yplayer;
	int		xenemy;
	int		yenemy;
	int		count;
	char	**arr;
	char	*ptr;
	int		pressed_key;
	int		number_of_collectible;
	int		number_of_moves;
	char	position_of_enemy;
	char	key;
}	t_bdata;

typedef struct s_bcomponents
{
	int	i;
	int	j;
	int	c;
	int	p;
	int	e;
	int	a;
}	t_bvar;

void	check_error_walls_bonus(char **arr, int rows, int columns);
void	check_validation_map_bonus(char **arr, int rows);
void	init_struct_components(t_bvar *v);
void	check_exist_of_components_bonus(char **arr, int rows);
void	check_if_map_rectangular_bonus(char **arr, int rows, int columns);
void	get_dimensions_bonus(char **arr, int *rows, int *columns);
void	move_d_bonus(t_bdata *vars, t_bimg *imgs);
void	move_a_bonus(t_bdata *vars, t_bimg *imgs);
void	move_w_bonus(t_bdata *vars, t_bimg *imgs);
void	move_s_bonus(t_bdata *vars, t_bimg *imgs);
void	reprint_map_part_2_bonus(t_bdata *vars, t_bimg *imgs, int i, int j);
void	reprint_map_part_1_bonus(t_bdata *vars, t_bimg *imgs);
void	reprint_map_bonus(t_bdata *vars, t_bimg *imgs, char key);
void	print_background_bonus(t_bdata *vars, void *img);
void	print_em_cases_bonus(t_bdata *vars, t_bimg *imgs, int i, int j);
void	print_elemets_of_map_bonus(t_bdata *vars, t_bimg *imgs);
void	check_map_bonus(t_bdata *vars, int rows, int columns);
void	convert_all_assets_of_map_bonus(t_bdata *vars, t_bimg *imgs);
void	count_number_of_collectible_bonus(t_bdata *vars);
void	reading_map_bonus(t_bdata *vars);
void	print_map_bonus(t_bdata *vars, t_bimg *imgs);
void	message_component_bonus(void);
void	message_error_bonus(void);
int		strlen_bonus(const char *str);
void	get_position_of_player_bonus(t_bdata *vars);
void	get_position_of_enemy_bonus(t_bdata *vars);
int		cross_bonus(t_bdata *vars);
void	fill_paths_bonus(t_bimg *imgs);
void	fill_dimensions_bonus(t_bimg *imgs, int rows, int columns);
int		moves_enemy(t_bdata *vars);
int		ft_strncmp1(char *s1, char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n, t_bdata *vars);
void	desplay_number_of_movement_with_message(t_bdata *vars);
char	**ft_split(char const *s, char c);
void	case_d_0_and_c(t_bdata *vars);
void	case_a_0_and_c(t_bdata *vars);
void	case_w_0_and_c(t_bdata *vars);
void	case_s_0_and_c(t_bdata *vars);
void	reprint_mp1_cases_bonus(t_bdata *vars, t_bimg *imgs, int i, int j);
void	key_bonus(t_bdata *vars);
void	free_and_close(t_bdata *vars);
void	check_extension_validation_b(char *str);
int		check_extension_b(char *str);
void	message_file_b(void);
void	message_empty_file_b(void);
void	message_check_map_b(void);
#endif