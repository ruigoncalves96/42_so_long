/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/26 16:40:45 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned int	ft_strlen_no_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_open_file(const char *map, mode_t open_mode)
{
	int	fd;

	fd = open(map, open_mode);
	if (fd < 0)
	{
		perror("Error\nDescription");
		return (1);
	}
	return (fd);
}

bool	ft_is_rectangle(const char *map, t_map_info *map_info)
{
	int	fd;
	char	*str;

	fd = ft_open_file(map, O_RDONLY);
	str = get_next_line(fd);
	map_info->size[0] = ft_strlen_no_nl(str);
	map_info->size[1]++;
	while(str)
	{
		free(str);
		str = get_next_line(fd);
		if (!str)
			break;
		map_info->size[1]++;
		if (ft_strlen_no_nl(str) != map_info->size[0])
		{
			ft_putstr_fd("Map not rectangle!\n", 2);
			exit(1);
		}
	}
	return (true);
}

//void	ft_read_map(const char *map)
//{
//
//}
//
//char	**ft_alloc_array(const char *map)
//{
//
//}

void	ft_initialize_t_map_info(t_map_info *map_info)
{
	map_info->size[0] = 0;
	map_info->size[1] = 0;
	map_info->wall = 0;
	map_info->floor = 0;
	map_info->player = 0;
	map_info->collectible = 0;
	map_info->exit = 0;
}

bool	ft_map_parsing(const char *map)
{
	t_map_info	map_info;

	ft_initialize_t_map_info(&map_info);
	ft_is_rectangle(map, &map_info);
	ft_printf("x = %d\ny = %d\n", map_info.size[0], map_info.size[1]);
	return (true);
}
