/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ppos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:47:49 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:48:09 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*get_ppos(t_data *data)
{
	t_point	*ppos;

	ppos = malloc(sizeof(t_point));
	if (ppos == NULL)
		error_exit("Failed to initialize game", data);
	ppos->x = 0;
	ppos->y = 0;
	get_ppos2(&ppos, data);
	if (ppos->x == 0 && ppos->y == 0)
	{
		free(ppos);
		error_exit("No player starting point", data);
	}
	return (ppos);
}

void	get_ppos2(t_point **ppos, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->len_y)
	{
		x = 0;
		while (x < data->map->len_x)
		{
			if (data->map->map[y][x] == 'P')
			{
				if ((*ppos)->x != 0 && (*ppos)->y != 0)
				{
					free(*ppos);
					error_exit("More than 1 initial player position", data);
				}
				(*ppos)->x = x;
				(*ppos)->y = y;
			}
			x++;
		}
		y++;
	}
}
