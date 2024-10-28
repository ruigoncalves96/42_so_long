/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 21:56:41 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_initialize_t_map_info(t_map_info *map_info)
{
	ft_memset(map_info, 0, sizeof(t_map_info));
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

void	ft_free_array(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
}
