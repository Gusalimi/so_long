/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:18:04 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 12:55:31 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42/MLX42.h"

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct s_map
{
	char			**map;
	int				len_x;
	int				len_y;
}					t_map;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_texture_t	*wttr;
	mlx_image_t		*wimg;
	mlx_texture_t	*pttr;
	mlx_image_t		*pimg;
	mlx_texture_t	*cttr;
	mlx_image_t		*cimg;
	mlx_texture_t	*ottr;
	mlx_image_t		*oimg;
	mlx_texture_t	*ettr;
	mlx_image_t		*eimg;
	mlx_texture_t	*kttr;
	mlx_image_t		*kimg;
	int				to_collect;
	int				collected;
	int				movements;
	char			*mvt_string;
	mlx_image_t		*mvt_img;
	t_map			*map;
	t_point			*ppos;
	int				won;
}					t_data;

#endif