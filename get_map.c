/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:16:15 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/05 14:51:30 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *fn)
{
	int	l;

	if (!fn || fn[0] == 0)
		error_exit("Invalid filename", NULL);
	l = ft_strlen(fn);
	if (l < 5 || fn[l - 1] != 'r' || fn[l - 2] != 'e' || fn[l - 3] != 'b'
		|| fn[l - 4] != '.')
		error_exit("Map is not a .ber file", NULL);
}

void	get_map_size(t_line *map_list, int *len_x, int *len_y, t_data *data)
{
	*len_x = (int)ft_strlen(map_list->line);
	*len_y = 0;
	while (map_list->next)
	{
		if ((int)ft_strlen(map_list->line) != *len_x)
		{
			ft_lstclear(&map_list, free);
			error_exit("Map is not a rectangle (or file has extra line)", data);
		}
		map_list = map_list->next;
		(*len_y)++;
	}
	if (map_list->line[ft_strlen(map_list->line) - 1] != '\n')
		(*len_x)--;
	(*len_y)++;
	if ((int)ft_strlen(map_list->line) != *len_x)
	{
		ft_lstclear(&map_list, free);
		error_exit("Map is not a rectangle", data);
	}
	if (map_list->line[ft_strlen(map_list->line) - 1] == '\n')
		(*len_x)--;
}

t_line	*get_map_list(char *filename, t_data *data)
{
	t_line	*map;
	t_line	*new_line;
	char	*line;
	int		fd;

	map = NULL;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		error_exit("Invalid filename or empty map", data);
	while (line)
	{
		new_line = ft_lstnew(line);
		if (!new_line)
		{
			ft_lstclear(&map, free);
			error_exit("Failed to load the map", data);
		}
		ft_lstadd_back(&map, new_line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_map	*get_map(char *filename, t_data *data)
{
	t_map	*map_s;
	t_line	*map_list;

	map_s = malloc(sizeof(t_map));
	if (map_s == NULL)
		error_exit("Failed to parse the map.", data);
	map_list = get_map_list(filename, data);
	get_map_size(map_list, &map_s->len_x, &map_s->len_y, data);
	map_s->map = malloc(sizeof(char *) * map_s->len_y);
	if (map_s->map == NULL)
	{
		free(map_s);
		error_exit("Failed to parse the map.", data);
	}
	get_map2(map_list, &map_s, data);
	ft_lstclear(&map_list, free);
	free(map_list);
	return (map_s);
}

void	get_map2(t_line *map_list, t_map **map_s, t_data *data)
{
	t_line	*current;
	int		y;
	int		x;

	y = 0;
	current = map_list;
	while (current)
	{
		x = 0;
		(*map_s)->map[y] = malloc(sizeof(char) * (*map_s)->len_x);
		if ((*map_s)->map[y] == NULL)
		{
			(*map_s)->len_y = y;
			free_map(*map_s);
			ft_lstclear(&map_list, free);
			error_exit("Failed to parse the map.", data);
		}
		while (x < (*map_s)->len_x)
		{
			(*map_s)->map[y][x] = current->line[x];
			x++;
		}
		y++;
		current = current->next;
	}
}
