/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:21:09 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 12:53:07 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map_s)
{
	int	y;

	y = 0;
	if (map_s)
	{
		if (map_s->map)
		{
			while (y < map_s->len_y)
			{
				free(map_s->map[y++]);
			}
			free(map_s->map);
		}
		free(map_s);
	}
}

void	free_data(void *param)
{
	t_data	*data;

	data = param;
	if (data)
	{
		if (data->map)
			free_map(data->map);
		if (data->ppos)
			free(data->ppos);
		if (data->mvt_string)
			free(data->mvt_string);
		if (data->mlx)
			mlx_terminate(data->mlx);
		free(data);
	}
}
