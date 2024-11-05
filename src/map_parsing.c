/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 14:36:52 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_is_playable(const char **map, t_map_info *map_info, t_player *player)
{
	char	**copy_map;

	copy_map = ft_array_dup(map, map_info);
	if (!copy_map)
		ft_perror_free_exit((char **)map);
	ft_flood_fill(copy_map, map_info, player->coord.y, player->coord.x);
	ft_free_array(copy_map);
	if (map_info->collectibles_reached == false || map_info->exit_reached == false)
		return (false);
	return (true);
}

static bool	ft_check_map_content(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < data->map_info.size.y)
	{
		x = 0;
		while (x < data->map_info.size.x)
		{
			if (ft_count_content(data->map[y][x], data, y, x) == false)
				return (false);
			x++;
		}
		y++;
	}
	if (data->map_info.player != 1 || data->map_info.collectibles == 0
		|| data->map_info.exit != 1)
		return (false);
	return (true);
}

static bool	ft_is_closed(const char **map, t_map_info *map_info)
{
	unsigned int	i;

	i = 0;
	while (*map)
	{
		if (i == 0 || i == map_info->size.y - 1)
		{
			if (ft_check_top_bottom_wall(*map, map_info) == false)
				return (false);
		}
		else
		{
			if (ft_check_left_right_wall(*map, map_info) == false)
				return (false);
		}
		i++;
		map++;
	}
	return (true);
}

static bool	ft_is_rectangle(const char **map, t_map_info *map_info)
{
	unsigned int	len;

	len = 0;
	map_info->size.x = ft_strlen(*map);
	while (*map)
	{
		len = ft_strlen(*map);
		if (len != map_info->size.x)
			return (false);
		map++;
	}
	return (true);
}

bool	ft_map_parsing(t_data *data)
{
	if (ft_is_rectangle(data->map, &data->map_info) == false)
		ft_fderror_free_exit(NOT_RECTANGLE_M, (char **)data->map);
	if (ft_is_closed(data->map, &data->map_info) == false)
		ft_fderror_free_exit(NOT_CLOSED_M, (char **)data->map);
	if (ft_check_map_content(data) == false)
		ft_fderror_free_exit(WRONG_CONTENT_M, (char **)data->map);
	if (ft_is_playable(data->map, &data->map_info, &data->player) == false)
		ft_fderror_free_exit(NOT_WINNABLE_M, (char **)data->map);
	return (true);
}
