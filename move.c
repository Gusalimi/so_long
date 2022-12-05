/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:28:12 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:49:46 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_data *data, char mvt)
{
	t_point	new_pos;

	if (mvt == 'U')
	{
		new_pos.x = data->ppos->x;
		new_pos.y = data->ppos->y - 1;
	}
	if (mvt == 'L')
	{
		new_pos.x = data->ppos->x - 1;
		new_pos.y = data->ppos->y;
	}
	if (mvt == 'D')
	{
		new_pos.x = data->ppos->x;
		new_pos.y = data->ppos->y + 1;
	}
	if (mvt == 'R')
	{
		new_pos.x = data->ppos->x + 1;
		new_pos.y = data->ppos->y;
	}
	return (data->map->map[new_pos.y][new_pos.x] != '1');
}

int	get_instance(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->to_collect)
	{
		if (data->cimg->instances[i].x == data->ppos->x * 64
			&& data->cimg->instances[i].y == data->ppos->y * 64)
			return (i);
		i++;
	}
	return (-1);
}

void	move(t_data *data, char mvt)
{
	change_knight_side(data, mvt);
	if (can_move(data, mvt))
	{
		if (mvt == 'U')
		{
			data->pimg->instances[0].y -= 64;
			data->ppos->y--;
		}
		if (mvt == 'L')
		{
			data->pimg->instances[0].x -= 64;
			data->ppos->x--;
		}
		if (mvt == 'D')
		{
			data->pimg->instances[0].y += 64;
			data->ppos->y++;
		}
		if (mvt == 'R')
		{
			data->pimg->instances[0].x += 64;
			data->ppos->x++;
		}
		move2(data);
	}
}

void	move2(t_data *d)
{
	if (d->map->map[d->ppos->y][d->ppos->x] == 'C')
	{
		d->cimg->instances[get_instance(d)].enabled = false;
		d->collected++;
		d->map->map[d->ppos->y][d->ppos->x] = '0';
		if (d->collected == d->to_collect)
			show_exit(d);
	}
	if (d->map->map[d->ppos->y][d->ppos->x] == 'K')
		mlx_close_window(d->mlx);
	if (d->map->map[d->ppos->y][d->ppos->x] == 'E'
		&& d->collected == d->to_collect)
	{
		d->won = 1;
		mlx_close_window(d->mlx);
	}
	d->movements++;
	mlx_delete_image(d->mlx, d->mvt_img);
	free(d->mvt_string);
	d->mvt_string = ft_strjoin("Mouvements : ", ft_itoa(d->movements));
	d->mvt_img = mlx_put_string(d->mlx, d->mvt_string, 10, d->map->len_y * 64
			+ 5);
}
