/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:47:24 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:48:13 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_data *data)
{
	int	x;
	int	y;
	int	nb;

	y = 0;
	nb = 0;
	while (y < data->map->len_y)
	{
		x = 0;
		while (x < data->map->len_x)
		{
			if (data->map->map[y][x] == 'E')
				nb++;
			x++;
		}
		y++;
	}
	if (nb > 1)
		error_exit("More than 1 exit", data);
	if (nb < 1)
		error_exit("No exit in the map", data);
}

void	null_data(t_data **data)
{
	(*data)->mlx = 0;
	(*data)->wttr = 0;
	(*data)->wimg = 0;
	(*data)->pttr = 0;
	(*data)->pimg = 0;
	(*data)->cttr = 0;
	(*data)->cimg = 0;
	(*data)->ottr = 0;
	(*data)->oimg = 0;
	(*data)->ettr = 0;
	(*data)->eimg = 0;
	(*data)->kttr = 0;
	(*data)->kimg = 0;
	(*data)->to_collect = 0;
	(*data)->collected = 0;
	(*data)->movements = 0;
	(*data)->mvt_string = 0;
	(*data)->map = 0;
	(*data)->ppos = 0;
	(*data)->won = 0;
}

t_data	*init_data(char *filename)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		error_exit("Failed to initialize game1", NULL);
	null_data(&data);
	data->map = get_map(filename, data);
	data->mlx = mlx_init(data->map->len_x * 64, data->map->len_y * 64 + 30,
			"so long", true);
	if (data->mlx == NULL)
		error_exit("Failed to initialize the game2", data);
	init_textures(data);
	data->ppos = get_ppos(data);
	data->to_collect = get_num_collect(data->map);
	if (data->to_collect < 1)
		error_exit("Failed to initialize the game15", data);
	data->mvt_string = ft_strjoin("Mouvements : ", ft_itoa(data->movements));
	if (data->mvt_string == NULL)
		error_exit("Failed to initialize the game16", data);
	data->mvt_img = mlx_put_string(data->mlx, data->mvt_string, 10,
			data->map->len_y * 64 + 5);
	if (data->mvt_img == NULL)
		error_exit("Failed to initialize the game17", data);
	data->mvt_img->instances[0].z = 1;
	return (data);
}

void	init_textures(t_data *data)
{
	data->pttr = mlx_load_png("sprites/Player_right.png");
	if (data->pttr == NULL)
		error_exit("Failed to initialize the game3", data);
	data->pimg = mlx_texture_to_image(data->mlx, data->pttr);
	if (data->pimg == NULL)
		error_exit("Failed to initialize the game4", data);
	data->ottr = mlx_load_png("sprites/Path.png");
	if (data->ottr == NULL)
		error_exit("Failed to initialize the game5", data);
	data->oimg = mlx_texture_to_image(data->mlx, data->ottr);
	if (data->oimg == NULL)
		error_exit("Failed to initialize the game6", data);
	data->wttr = mlx_load_png("sprites/Wall.png");
	if (data->wttr == NULL)
		error_exit("Failed to initialize the game7", data);
	data->wimg = mlx_texture_to_image(data->mlx, data->wttr);
	if (data->wimg == NULL)
		error_exit("Failed to initialize the game8", data);
	init_textures2(data);
}

void	init_textures2(t_data *data)
{
	data->cttr = mlx_load_png("sprites/Carrot1.png");
	if (data->cttr == NULL)
		error_exit("Failed to initialize the game9", data);
	data->cimg = mlx_texture_to_image(data->mlx, data->cttr);
	if (data->cimg == NULL)
		error_exit("Failed to initialize the game10", data);
	data->ettr = mlx_load_png("sprites/Exit.png");
	if (data->ettr == NULL)
		error_exit("Failed to initialize the game11", data);
	data->eimg = mlx_texture_to_image(data->mlx, data->ettr);
	if (data->eimg == NULL)
		error_exit("Failed to initialize the game12", data);
	data->kttr = mlx_load_png("sprites/Enemy_right.png");
	if (data->kttr == NULL)
		error_exit("Failed to initialize the game13", data);
	data->kimg = mlx_texture_to_image(data->mlx, data->kttr);
	if (data->kimg == NULL)
		error_exit("Failed to initialize the game14", data);
}
