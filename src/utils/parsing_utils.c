/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/29 11:45:50 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned int	ft_flood_fill(char **map, t_map_info *map_info,
					unsigned int y, unsigned int x)
{
	unsigned int	collectibles;

	collectibles = 0;
	if (map[y][x] == 'E')
		map_info->exit_reached = true;
	if (x >= map_info->size_x || x < 0 || y >= map_info->size_y || y < 0
		|| (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P'))
		return (collectibles);
	if (map[y][x] == 'C')
		collectibles++;
	map[y][x] = 'F';
	collectibles += ft_flood_fill(map, map_info, y + 1, x);
	collectibles += ft_flood_fill(map, map_info, y - 1, x);
	collectibles += ft_flood_fill(map, map_info, y, x + 1);
	collectibles += ft_flood_fill(map, map_info, y, x - 1);
	if (collectibles == map_info->collectibles)
		map_info->collectibles_reached = true;
	return (collectibles);
}

bool	ft_count_content(char content, t_map_info *map_info,
					unsigned int y, unsigned int x)
{
	if (content == '0')
		map_info->floors++;
	else if (content == '1')
		map_info->walls++;
	else if (content == 'P')
	{
		map_info->player++;
		map_info->player_coord.y = y;
		map_info->player_coord.x = x;
	}
	else if (content == 'C')
		map_info->collectibles++;
	else if (content == 'E')
		map_info->exit++;
	else
		return (false);
	return (true);
}

bool	ft_check_top_bottom_wall(const char *map, t_map_info *map_info)
{
	unsigned int	i;

	(void)map_info;
	i = 0;
	while (map[i])
	{
		if (map[i] == '1')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	ft_check_left_right_wall(const char *map, t_map_info *map_info)
{
	if (map[0] != '1' || map[map_info->size_x - 1] != '1')
		return (false);
	return (true);
}