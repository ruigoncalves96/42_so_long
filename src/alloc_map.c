/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/11/06 13:30:21 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_copy_line(int fd)
{
	char	*temp;
	char	*new_line;

	temp = get_next_line(fd);
	new_line = ft_strtrim(temp, "\n");
	free(temp);
	return (new_line);
}

static unsigned int	ft_paragraph_len(const char *map)
{
	char	*str;
	int		fd;
	int		len;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_perror_exit();
	str = get_next_line(fd);
	if (!str)
		ft_fderror_exit(EMPTY_M);
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
	unsigned int		i;
	char				**ptr;
	int					fd;

	map_info->size.y = ft_paragraph_len(map);
	ptr = ft_calloc(map_info->size.y + 1, sizeof(char *));
	if (!ptr)
		ft_perror_exit();
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_perror_free_exit(ptr);
	i = 0;
	while (i < map_info->size.y)
	{
		ptr[i] = ft_copy_line(fd);
		if (!ptr[i])
			ft_perror_free_exit(ptr);
		i++;
	}
	ptr[i] = NULL;
	close(fd);
	return (ptr);
}
