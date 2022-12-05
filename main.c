/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:24:57 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 13:33:06 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		move(data, 'U');
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		move(data, 'L');
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		move(data, 'D');
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		move(data, 'R');
}

void	anim_enemy(void *param)
{
	static int	frames;
	t_data		*data;

	data = param;
	if (frames == ANIMATION)
		change_enemy_side(data, 'U');
	if (frames == ANIMATION * 2)
		change_enemy_side(data, 'L');
	if (frames == ANIMATION * 3)
		change_enemy_side(data, 'D');
	if (frames == ANIMATION * 4)
	{
		change_enemy_side(data, 'R');
		frames = -1;
	}
	frames++;
}

void	final_message(t_data *data)
{
	if (data->won)
		ft_printf("\033[1m\033[32mCongratulations !\033[0m\n");
	else
		ft_printf("\033[1m\033[31mGame OVER !\033[0m\n");
}

int	main(int argc, char **argv)
{
	t_data	*d;
	t_map	*copy;

	if (argc == 1)
		error_exit("Usage : ./so_long map_name.ber", NULL);
	if (argc > 2)
	{
		ft_putstr_fd("\033[1m\033[33mWarning\033[0m\n", 2);
		ft_putstr_fd("More than 1 map passed, only 1st one will be used\n", 2);
	}
	check_filename(argv[1]);
	d = init_data(argv[1]);
	check_exit(d);
	is_surrounded(d);
	copy = copy_map(d);
	check_path(copy, d);
	free_map(copy);
	print_map(d);
	mlx_image_to_window(d->mlx, d->pimg, d->ppos->x * 64, d->ppos->y * 64);
	mlx_key_hook(d->mlx, hook, d);
	mlx_loop_hook(d->mlx, anim_enemy, d);
	mlx_loop(d->mlx);
	final_message(d);
	free_data(d);
	return (0);
}

//ft_printf("\n\nmap :\n");
// y = 0;
// while (y < data->map->len_y)
// {
// 	x = 0;
// 	while (x < data->map->len_x)
// 		ft_printf("%c ", data->map->map[y][x++]);
// 	ft_printf("\n");
// 	y++;
// }