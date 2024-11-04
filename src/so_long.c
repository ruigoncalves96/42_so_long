/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/11/04 16:48:01 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	t_data	data;

	if (argc != 2)
		ft_fderror_exit(WRONG_FORMAT_M);
	ft_is_file_readable(argv[1]);
	ft_initialize_t_map_info(&map_info);
	ft_initialize_t_data(&data);
	data.map = (const char **)ft_alloc_map_array(argv[1], &map_info);
	ft_map_parsing(data.map, &map_info);
	ft_print_array(data.map);
	ft_window(&data, &map_info);
	ft_free_array((char **)data.map);
}


// CHECK INITIALIZE STRUCTS!!!!! #########
