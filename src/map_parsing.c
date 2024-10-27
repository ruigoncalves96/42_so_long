/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:11:31 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 12:44:46 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	ft_map_parsing(const char *map)
{
	ft_print_array(map_array);
	ft_free_array(map_array);
	free(map_array);
	return (true);
}
