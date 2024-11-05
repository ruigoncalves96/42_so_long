/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 13:49:06 by randrade         ###   ########.fr       */
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

void	ft_initialize_t_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	ft_memset(&data->mlx, 0, sizeof(t_mlx));
	ft_memset(&data->player, 0, sizeof(t_player));
	ft_memset(&data->player.img, 0, sizeof(t_image));
	ft_memset(&data->player.coord, 0, sizeof(t_coord));
	ft_memset(&data->collect, 0, sizeof(t_collect));
	ft_memset(&data->collect.img, 0, sizeof(t_image));
	ft_memset(&data->exit, 0, sizeof(t_image));
	ft_memset(&data->wall, 0, sizeof(t_image));
	ft_memset(&data->floor, 0, sizeof(t_image));
	ft_memset(&data->map_info, 0, sizeof(t_map_info));
	ft_memset(&data->map_info.size, 0, sizeof(t_coord));
}
