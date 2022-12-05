/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:03:09 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:05:20 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*copy_map(t_data *data)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (new_map == NULL)
		error_exit("Failed to initialize the game", data);
	new_map->len_x = data->map->len_x;
	new_map->len_y = data->map->len_y;
	new_map->map = malloc(data->map->len_y * sizeof(char *));
	if (new_map->map == NULL)
		error_exit("Failed to initialize the game", data);
	copy_map2(&new_map, data);
	return (new_map);
}

void	copy_map2(t_map **new_map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*new_map)->len_y)
	{
		(*new_map)->map[y] = malloc((*new_map)->len_x * sizeof(char));
		if ((*new_map)->map[y] == NULL)
		{
			(*new_map)->len_y = y;
			free_map(*new_map);
			error_exit("Failed to initialize the game", data);
		}
		x = 0;
		while (x < (*new_map)->len_x)
		{
			(*new_map)->map[y][x] = data->map->map[y][x];
			x++;
		}
		y++;
	}
}
