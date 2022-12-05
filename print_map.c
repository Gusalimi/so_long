/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:23:20 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:46:51 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_bg(t_data *data)
{
	int			x;
	int			y;
	mlx_image_t	*background;

	y = 0;
	background = mlx_new_image(data->mlx, data->map->len_x * 64,
			data->map->len_y * 64);
	while (y < data->map->len_y * 64)
	{
		x = 0;
		while (x < data->map->len_x * 64)
			mlx_put_pixel(background, x++, y, 0x000000FF);
		y++;
	}
	mlx_image_to_window(data->mlx, background, 0, 0);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	print_bg(data);
	y = -1;
	while (++y < data->map->len_y)
	{
		x = -1;
		while (++x < data->map->len_x)
		{
			if (data->map->map[y][x] == '0' || data->map->map[y][x] == 'P'
				|| data->map->map[y][x] == 'C' || data->map->map[y][x] == 'E'
				|| data->map->map[y][x] == 'K')
				mlx_image_to_window(data->mlx, data->oimg, x * 64, y * 64);
			else if (data->map->map[y][x] == '1')
				mlx_image_to_window(data->mlx, data->wimg, x * 64, y * 64);
			else
				error_exit("Too many symbols in map", data);
			if (data->map->map[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->cimg, x * 64, y * 64);
			if (data->map->map[y][x] == 'K')
				mlx_image_to_window(data->mlx, data->kimg, x * 64, y * 64);
		}
	}
}

void	show_exit(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->len_y)
	{
		x = 0;
		while (x < data->map->len_x)
		{
			if (data->map->map[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->eimg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
