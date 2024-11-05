/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 16:22:31 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_move_player_left(t_data *data)
{
	if (data->map[data->player.coord.y][data->player.coord.x - 1] == '1')
		return (false);
	if (data->map[data->player.coord.y][data->player.coord.x - 1] == 'E')
	{
		if (data->exit.is_open == false)
			return (false);
		else
			ft_full_free(data);
	}
	if (data->map[data->player.coord.y][data->player.coord.x - 1] == 'C')
		data->collect.count++;
	data->moves++;
	ft_printf("Moves - %d\n", data->moves);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	data->player.coord.x -= 1;
	return (true);
}

static bool	ft_move_player_right(t_data *data)
{
	if (data->map[data->player.coord.y][data->player.coord.x + 1] == '1')
		return (false);
	if (data->map[data->player.coord.y][data->player.coord.x + 1] == 'E')
	{
		if (data->exit.is_open == false)
			return (false);
		else
			ft_full_free(data);
	}
	if (data->map[data->player.coord.y][data->player.coord.x + 1] == 'C')
		data->collect.count++;
	data->moves++;
	ft_printf("Moves - %d\n", data->moves);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	data->player.coord.x += 1;
	return (true);
}

static bool	ft_move_player_down(t_data *data)
{
	if (data->map[data->player.coord.y + 1][data->player.coord.x] == '1')
		return (false);
	if (data->map[data->player.coord.y + 1][data->player.coord.x] == 'E')
	{
		if (data->exit.is_open == false)
			return (false);
		else
			ft_full_free(data);
	}
	if (data->map[data->player.coord.y + 1][data->player.coord.x] == 'C')
		data->collect.count++;
	data->moves++;
	ft_printf("Moves - %d\n", data->moves);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	data->player.coord.y += 1;
	return (true);
}

static bool	ft_move_player_up(t_data *data)
{
	if (data->map[data->player.coord.y - 1][data->player.coord.x] == '1')
		return (false);
	if (data->map[data->player.coord.y - 1][data->player.coord.x] == 'E')
	{
		if (data->exit.is_open == false)
			return (false);
		else
			ft_full_free(data);
	}
	if (data->map[data->player.coord.y - 1][data->player.coord.x] == 'C')
		data->collect.count++;
	data->moves++;
	ft_printf("Moves - %d\n", data->moves);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	data->player.coord.y -= 1;
	return (true);
}

int	ft_key_handler(int keycode, t_data *data)
{
	if (keycode == 123 || keycode == 0)
		ft_move_player_left(data);
	else if (keycode == 124 || keycode == 2)
		ft_move_player_right(data);
	else if (keycode == 125 || keycode == 1)
		ft_move_player_down(data);
	else if (keycode == 126 || keycode == 13)
		ft_move_player_up(data);
	else if (keycode == 53)
		ft_full_free(data);
	if (data->collect.count == data->map_info.collectibles)
		data->exit.is_open = true;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img,
			data->player.coord.x * 32, data->player.coord.y * 32);
	return (0);
}
