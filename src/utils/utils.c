/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/28 14:31:38 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_array_dup(const char **map, t_map_info *map_info)
{
	char	**copy_map;
	int	y;

	y = 0;
	copy_map = calloc((map_info->size_y + 1), sizeof(char *));
	if (!copy_map)
		return(NULL);
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
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
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
	ft_memset(map_info, 0, sizeof(t_map_info));
}
