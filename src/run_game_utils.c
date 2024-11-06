/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/06 13:33:33 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_data *data)
{
	data->moves++;
	ft_printf("Moves - %d\n", data->moves);
}

void	ft_update_player_position(t_data *data, unsigned int y, unsigned int x)
{
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
		x * 32, y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
		data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img,
		data->player.coord.x * 32, data->player.coord.y * 32);
	ft_print_moves(data);
}

//void	ft_check_screen_map_size(t_data *data)
//{
//	mlx_get_screen_size(data->mlx.init, data->screen.x, data->screen.y);
//	if (data->screen.x < data->map_info.size.x
//		|| data->screen.y < data->map_info.size.y)
//		ft_size_map_error(data);
//}
