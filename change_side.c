/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:49:22 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:49:42 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_knight_side(t_data *d, char direction)
{
	mlx_delete_texture(d->pttr);
	mlx_delete_image(d->mlx, d->pimg);
	if (direction == 'R')
		d->pttr = mlx_load_png("sprites/Player_right.png");
	else if (direction == 'L')
		d->pttr = mlx_load_png("sprites/Player_left.png");
	if (direction == 'U')
		d->pttr = mlx_load_png("sprites/Player_up.png");
	else if (direction == 'D')
		d->pttr = mlx_load_png("sprites/Player_down.png");
	if (d->pttr == NULL)
		error_exit("Failed to load player", d);
	d->pimg = mlx_texture_to_image(d->mlx, d->pttr);
	if (d->pimg == NULL)
		error_exit("Failed to load player", d);
	mlx_image_to_window(d->mlx, d->pimg, d->ppos->x * 64, d->ppos->y * 64);
}

void	change_enemy_side(t_data *data, char mvt)
{
	int	x;
	int	y;

	y = -1;
	mlx_delete_texture(data->kttr);
	mlx_delete_image(data->mlx, data->kimg);
	if (mvt == 'R')
		data->kttr = mlx_load_png("sprites/Enemy_right.png");
	else if (mvt == 'L')
		data->kttr = mlx_load_png("sprites/Enemy_left.png");
	else if (mvt == 'D')
		data->kttr = mlx_load_png("sprites/Enemy_down.png");
	else if (mvt == 'U')
		data->kttr = mlx_load_png("sprites/Enemy_up.png");
	data->kimg = mlx_texture_to_image(data->mlx, data->kttr);
	while (++y < data->map->len_y)
	{
		x = -1;
		while (++x < data->map->len_x)
		{
			if (data->map->map[y][x] == 'K')
				mlx_image_to_window(data->mlx, data->kimg, x * 64, y * 64);
		}
	}
}
