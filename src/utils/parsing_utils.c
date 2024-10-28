/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 23:47:40 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//bool	ft_is_winnable(const char **map)
//{
//	unsigned int	y;
//	char	*exit;
//
//	y = 0;
//	while (map[y])
//	{
//		if (ft_strchar(map[y], 'C') == 'C')
//		{
//			ft_putstr_fd("Exit\nDescription: Can't collect everything!\n", 2);
//			ft_free_array(map);
//			free(map);
//			exit(1);
//		}
//		exit = ft_strchar(map[y], 'E');
//		if (exit[y][0] == 'E')
//		{
//			if (exit[y + 1][0] != 'F' || exit[y - 1][0] != 'F' || exit[y][x + 1] != 'F' || exit[y][x - 1] != 'F')
//			{
//				ft_putchar_fd("Exit\nDescription: Can't reach the exit!\n", 2);
//				ft_free_array(map);
//				free(map);
//				exit(1);
//			}
//		}
//		y++;
//	}
//	return (true);
//}

void	ft_flood_fill(char **map, t_map_info *map_info, unsigned int x, unsigned int y)
{
	if (x >= map_info->size_x || x < 0 || y >= map_info->size_y || y < 0 || (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P'))
		return ;
	map[y][x] = 'F';
	ft_flood_fill(map, map_info, x, y + 1);
	ft_flood_fill(map, map_info, x, y - 1);
	ft_flood_fill(map, map_info, x + 1, y);
	ft_flood_fill(map, map_info, x - 1, y);
}

void	ft_count_content(char content, t_map_info *map_info, unsigned int x, unsigned int y)
{
	if (content == '0')
		map_info->floor++;
	else if (content == '1')
		map_info->wall++;
	else if (content == 'P')
	{
		map_info->player++;
		map_info->player_coord.x = x;
		map_info->player_coord.y = y;
	}
	else if (content == 'C')
		map_info->collectible++;
	else if (content == 'E')
		map_info->exit++;
	else
	{
		ft_putstr_fd("Exit\nDescription: Not the right content!\n", 2);
		exit(1);
	}
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
		{
			ft_putstr_fd("Exit\nDescription: Map not closed!\n", 2);
			exit(1);
		}
	}
	return (true);
}

bool	ft_check_left_right_wall(const char *map, t_map_info *map_info)
{
	if (map[0] != '1' || map[map_info->size_x - 1] != '1')
	{
		ft_putstr_fd("Error\nDescription: Map not closed!\n", 2);
		exit(1);
	}
	return (true);
}
