/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 12:42:39 by randrade         ###   ########.fr       */
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
