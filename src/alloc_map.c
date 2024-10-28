/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 14:14:04 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_open_file(const char *map, mode_t open_mode)
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

static unsigned int	ft_paragraph_len(const char *map)
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
		free(str);
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

	map_info->size_y = ft_paragraph_len(map);
	ptr = ft_calloc(map_info->size_y + 1, sizeof(char *));
	if (!ptr)
	{
		perror("Error\nDescription:");
		exit(0);
	}
	fd = ft_open_file(map, O_RDONLY);
	i = 0;
	while (i < map_info->size_y)
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
