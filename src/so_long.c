/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/10/28 16:20:06 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	const char	**map;

	if (argc != 2)
		ft_fderror_exit(WRONG_FORMAT_M);
	ft_is_file_readable(argv[1]);
	ft_initialize_t_map_info(&map_info);
	map = (const char **)ft_alloc_map_array(argv[1], &map_info);
	ft_map_parsing(map, &map_info);
	ft_print_array(map);
	ft_free_array((char **)map);
}
