/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/10/27 21:56:30 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	const char	**map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nDescription: Wrong format! # './so_long *.ber'\n", 2);
		return (1);
	}
	ft_is_file_readble(argv[1]);				// CHECK MAP FILE
	ft_initialize_t_map_info(&map_info);			// INITIALIZE MAP_INFO
	map = (const char **)ft_alloc_map_array(argv[1], &map_info);		// CREATES MAP ARRAY
//	ft_print_array(map);
	ft_map_parsing(map, &map_info);
	ft_free_array((char **)map);
	free(map);
}
