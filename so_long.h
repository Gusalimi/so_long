/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:16:30 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:50:13 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "defines.h"
# include "includes.h"
# include "libft/libft.h"
# include "structs.h"

void	check_filename(char *fn);
t_line	*get_map_list(char *filename, t_data *data);
t_map	*get_map(char *filename, t_data *data);
void	get_map2(t_line *map_list, t_map **map_s, t_data *data);
t_map	*copy_map(t_data *data);
void	copy_map2(t_map **new_map, t_data *data);
t_data	*init_data(char *filename);
void	init_textures(t_data *data);
void	init_textures2(t_data *data);
t_point	*get_ppos(t_data *data);
void	get_ppos2(t_point **ppos, t_data *data);
void	is_surrounded(t_data *data);
void	error_exit(char *error_message, t_data *data);
void	print_map(t_data *data);
void	move(t_data *data, char mvt);
void	move2(t_data *d);
void	show_exit(t_data *data);
void	change_knight_side(t_data *d, char direction);
void	change_enemy_side(t_data *data, char mvt);
void	free_data(void *param);
void	free_map(t_map *map_s);
int		can_move(t_data *data, char mvt);
void	check_exit(t_data *data);
int		check_path(t_map *map, t_data *data);
int		get_num_collect(t_map *map_s);
void	get_map_size(t_line *map_list, int *len_x, int *len_y, t_data *data);

#endif