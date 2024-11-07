/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/11/07 14:06:44 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_run_game(t_data *data)
{
	data->mlx.init = mlx_init();
	if (data->mlx.init == NULL)
		ft_perror_free_exit((char **)data->map);
	ft_check_screen_map_size(data);
	data->mlx.win = mlx_new_window(data->mlx.init, (data->map_info.size.x
				* IMG_RES), (data->map_info.size.y * IMG_RES), "so_long");
	if (data->mlx.win == NULL)
		ft_perror_free_exit((char **)data->map);
	ft_draw_map(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, ft_key_handler, data);
	mlx_hook(data->mlx.win, 17, 0, ft_close_game, data);
	mlx_loop(data->mlx.init);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		ft_fderror_exit(WRONG_FORMAT_M);
	ft_is_file_readable(argv[1]);
	ft_initialize_t_data(&data);
	data.map = (const char **)ft_alloc_map_array(argv[1], &data.map_info);
	ft_map_parsing(&data);
	ft_run_game(&data);
}
