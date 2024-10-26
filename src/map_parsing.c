/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/26 20:02:56 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_initialize_t_map_info(t_map_info *map_info)
{
	map_info->size_xy[0] = 0;
	map_info->size_xy[1] = 0;
	map_info->wall = 0;
	map_info->floor = 0;
	map_info->player = 0;
	map_info->collectible = 0;
	map_info->exit = 0;
}

void	ft_print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

void	ft_free_array(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
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

unsigned int	ft_paragraph_len(const char *map)
{
	int	fd;
	int	len;
	char	*str;

	fd = ft_open_file(map, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
	{
		ft_putstr_fd("Error\nDescription: Map not rectangle!\n", 2);
		exit(1);
	}
	len = 1;
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			len++;
	}
	close(fd);
	return (len);
}

char	**ft_alloc_map_array(const char *map, t_map_info *map_info)
{
	unsigned int	i;
	int	fd;
	char	*temp;
	char	**ptr;

	map_info->size_xy[1] = ft_paragraph_len(map);
	ptr = ft_calloc(map_info->size_xy[1] + 1, sizeof(char *));
	if (!ptr)
	{
		perror("Error\nDescription:");
		exit(0);
	}
	fd = ft_open_file(map, O_RDONLY);
	i = 0;
	while (i < map_info->size_xy[1])
	{
		temp = get_next_line(fd);
		ptr[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	ptr[i] = NULL;
	close(fd);
	return (ptr);
}

bool	ft_map_parsing(const char *map)
{
	t_map_info	map_info;
	char	**map_array;

	ft_initialize_t_map_info(&map_info);
	map_array = ft_alloc_map_array(map, &map_info);
	ft_print_array(map_array);
	ft_free_array(map_array);
	free(map_array);
	return (true);
}

//	CHECK MEMORY LEAK GET_NEXT_LINE;
