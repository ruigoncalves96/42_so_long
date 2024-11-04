/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/11/04 16:47:30 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_array_dup(const char **map, t_map_info *map_info)
{
	char	**copy_map;
	int		y;

	y = 0;
	copy_map = calloc((map_info->size.y + 1), sizeof(char *));
	if (!copy_map)
		return (NULL);
	while (map[y])
	{
		copy_map[y] = ft_strdup(map[y]);
		if (!copy_map[y])
		{
			ft_free_array(copy_map);
			return (NULL);
		}
		y++;
	}
	copy_map[y] = NULL;
	return (copy_map);
}

void	ft_print_array(const char **str)
{
	while (*str)
	{
		ft_printf("%s\n", *str);
		str++;
	}
}

void	ft_free_array(char **array)
{
	char	**og_array;

	og_array = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(og_array);
}

void	ft_initialize_t_map_info(t_map_info *map_info)
{
	ft_memset(map_info, 0, sizeof(map_info));
	ft_memset(&map_info->size, 0, sizeof(map_info->size));
	ft_memset(&map_info->player_c, 0, sizeof(map_info->player_c));
	map_info->exit = 0;
}

void	ft_initialize_t_data(t_data *data)
{
	ft_memset(data, 0, sizeof(data));
	ft_memset(&data->player, 0, sizeof(data->player));
	ft_memset(&data->wall, 0, sizeof(data->wall));
	ft_memset(&data->floor, 0, sizeof(data->floor));
	ft_memset(&data->collect, 0, sizeof(data->collect));
	ft_memset(&data->exit, 0, sizeof(data->exit));
	ft_memset(&data->player_c, 0, sizeof(data->player_c));
}
