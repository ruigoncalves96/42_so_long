/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 23:49:27 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	ft_is_playable(const char **map, t_map_info *map_info)
{
	char	**copy_map;
	int	y;

	y = 0;
	copy_map = calloc((map_info->size_y + 1), sizeof(char *));
	if (!copy_map)
	{
		perror("Exit\nDescription");
		exit(1);
	}
	while (map[y])
	{
		copy_map[y] = ft_strdup(map[y]);
		if (!copy_map[y])
		{
			perror("Exit\nDescription");
			ft_free_array(copy_map);
			free(copy_map);
			exit(1);
		}
		y++;
	}
	copy_map[y] = NULL;
	ft_flood_fill(copy_map, map_info, map_info->player_coord.x, map_info->player_coord.y);
//	ft_is_winnable((const char **)copy_map);
	ft_print_array((const char **)copy_map);
	ft_free_array(copy_map);
	free(copy_map);
	return (true);
//	CHECK NO COLLECTABLES AND EXIT HAS AN F ARROUND
}

static bool	ft_check_map_content(const char **map, t_map_info *map_info)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < map_info->size_y)
	{
		x = 0;
		while (x < map_info->size_x)
		{
			ft_count_content(map[y][x], map_info, x, y);
			x++;
		}
		y++;
	}
	if (map_info->player != 1 || map_info->collectible == 0 || map_info->exit != 1)
	{
		ft_putstr_fd("Exit\nDescription: Not the right content!\n", 2);
		exit(1);
	}
	return (true);
}

static bool	ft_is_closed(const char **map, t_map_info *map_info)
{
	unsigned int	i;
	unsigned int	y;

	y = 0;
	i = 0;
	while (i < map_info->size_y)
	{
		if (i == 0 || i == map_info->size_y - 1)
			ft_check_top_bottom_wall(map[y], map_info);
		else
			ft_check_left_right_wall(map[y], map_info);
		i++;
		y++;
	}
	return (true);
}

static bool	ft_is_rectangle(const char **map, t_map_info *map_info)
{
	unsigned int	len;
	unsigned int	y;

	len = 0;
	y = 0;
	map_info->size_x = ft_strlen(map[y]);
	while (y < map_info->size_y)
	{
		len = ft_strlen(map[y]);
		if (len != map_info->size_x)
		{
			ft_putstr_fd("Error\nDescription: Not a rectangle!\n", 2);
			exit(1);
		}
		y++;
	}
	return (true);
}

bool	ft_map_parsing(const char **map, t_map_info *map_info)
{
	ft_is_rectangle(map, map_info);
	ft_is_closed(map, map_info);
	ft_check_map_content(map, map_info);
	ft_is_playable(map, map_info);
	return (true);
}
