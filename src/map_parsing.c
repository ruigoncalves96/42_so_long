/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/29 11:49:32 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_is_playable(const char **map, t_map_info *map_info)
{
	char	**copy_map;

	copy_map = ft_array_dup(map, map_info);
	if (!copy_map)
		ft_perror_free_exit((char **)map);
	ft_flood_fill(copy_map, map_info, map_info->player_coord.y,
			map_info->player_coord.x);
	if (map_info->collectibles_reached == false || map_info->exit_reached == false)
	{
		ft_free_array(copy_map);
		ft_fderror_free_exit(NOT_WINNABLE_M, (char **)map);
	}
	ft_free_array(copy_map);
	return (true);
}

static bool	ft_check_map_content(const char **map, t_map_info *map_info)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map_info->size_y)
	{
		x = 0;
		while (x < map_info->size_x)
		{
			if (ft_count_content(map[y][x], map_info, y, x) == false)
				ft_fderror_free_exit(WRONG_CONTENT_M, (char **)map);
			x++;
		}
		y++;
	}
	if (map_info->player != 1 || map_info->collectibles == 0
		|| map_info->exit != 1)
		ft_fderror_free_exit(WRONG_CONTENT_M, (char **)map);
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
		{
			if (ft_check_top_bottom_wall(map[y], map_info) == false)
				ft_fderror_free_exit(NOT_CLOSED_M, (char **)map);
		}
		else
		{
			if (ft_check_left_right_wall(map[y], map_info) == false)
				ft_fderror_free_exit(NOT_CLOSED_M, (char **)map);
		}
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
			ft_fderror_free_exit(NOT_RECTANGLE_M, (char **)map);
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
