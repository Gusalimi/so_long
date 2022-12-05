/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:45:14 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 14:49:29 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*flood_fill(char **tab, t_point size, t_point cur, char wall)
{
	static int	n[2] = {0, 0};

	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| tab[cur.y][cur.x] == wall || tab[cur.y][cur.x] == 'K')
		return (NULL);
	if (tab[cur.y][cur.x] == 'C')
		n[0]++;
	if (tab[cur.y][cur.x] == 'E')
		n[1]++;
	tab[cur.y][cur.x] = wall;
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, wall);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, wall);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, wall);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, wall);
	return ((int *)n);
}

int	get_num_collect(t_map *map_s)
{
	int	x;
	int	y;
	int	total;

	total = 0;
	y = 0;
	while (y < map_s->len_y)
	{
		x = 0;
		while (x < map_s->len_x)
		{
			if (map_s->map[y][x++] == 'C')
				total++;
		}
		y++;
	}
	return (total);
}

void	is_surrounded(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map->len_x)
	{
		if (data->map->map[0][x++] != '1')
			error_exit("Map is not surrounded by walls", data);
	}
	while (y < data->map->len_y - 1)
	{
		if (data->map->map[y][0] != '1' || data->map->map[y][data->map->len_x
			- 1] != '1')
			error_exit("Map is not surrounded by walls", data);
		y++;
	}
	x = 0;
	while (x < data->map->len_x)
	{
		if (data->map->map[y][x++] != '1')
			error_exit("Map is not surrounded by walls", data);
	}
}

int	check_path(t_map *m, t_data *data)
{
	int	*n;
	int	num_consum;

	num_consum = get_num_collect(m);
	n = flood_fill(m->map, (t_point){m->len_x, m->len_y}, *(data->ppos), '1');
	if (n[1] != 1)
	{
		free_map(m);
		error_exit("Exit is not available", data);
	}
	if (n[0] < 1)
	{
		free_map(m);
		error_exit("There must be at least 1 collectible", data);
	}
	if (n[0] < num_consum)
	{
		free_map(m);
		error_exit("All collectible should be available", data);
	}
	return (n[0]);
}
