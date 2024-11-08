/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/08 12:16:50 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_data *data)
{
	data->moves++;
	ft_printf("Moves - %u\n", data->moves);
}

void	ft_update_player_position(char **map, t_data *data, unsigned int y,
		unsigned int x)
{
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
		x * IMG_RES, y * IMG_RES);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img,
		data->player.coord.x * IMG_RES, data->player.coord.y * IMG_RES);
	if (map[y][x] == 'C')
		map[y][x] = '0';
	map[data->player.coord.y][data->player.coord.x] = 'P';
	ft_print_moves(data);
}

void	ft_check_screen_map_size(t_data *data)
{
	int	screen_x;
	int	screen_y;

	mlx_get_screen_size(data->mlx.init, &screen_x, &screen_y);
	if (screen_x < ((int)data->map_info.size.x * IMG_RES)
		|| screen_y < ((int)data->map_info.size.y * IMG_RES))
		ft_size_map_error(data);
}
