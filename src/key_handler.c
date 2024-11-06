/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/06 15:46:07 by randrade         ###   ########.fr       */
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
		{
			ft_print_moves(data);
			ft_close_game(data);
		}
	}
	if (data->map[data->player.coord.y][data->player.coord.x - 1] == 'C')
		data->collect.count++;
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
		{
			ft_print_moves(data);
			ft_close_game(data);
		}
	}
	if (data->map[data->player.coord.y][data->player.coord.x + 1] == 'C')
		data->collect.count++;
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
		{
			ft_print_moves(data);
			ft_close_game(data);
		}
	}
	if (data->map[data->player.coord.y + 1][data->player.coord.x] == 'C')
		data->collect.count++;
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
		{
			ft_print_moves(data);
			ft_close_game(data);
		}
	}
	if (data->map[data->player.coord.y - 1][data->player.coord.x] == 'C')
		data->collect.count++;
	data->player.coord.y -= 1;
	return (true);
}

int	ft_key_handler(int keycode, t_data *data)
{
	unsigned int	y;
	unsigned int	x;
	bool			player_move;

	y = data->player.coord.y;
	x = data->player.coord.x;
	player_move = false;
	if (keycode == LEFT_ARROW || keycode == LEFT_A)
		player_move = ft_move_player_left(data);
	else if (keycode == RIGHT_ARROW || keycode == RIGHT_D)
		player_move = ft_move_player_right(data);
	else if (keycode == DOWN_ARROW || keycode == DOWN_S)
		player_move = ft_move_player_down(data);
	else if (keycode == UP_ARROW || keycode == UP_W)
		player_move = ft_move_player_up(data);
	else if (keycode == ESC)
		ft_close_game(data);
	if (data->collect.count == data->map_info.collectibles)
		data->exit.is_open = true;
	if (player_move == true)
		ft_update_player_position((char **)data->map, data, y, x);
	if (data->moves >= MAX_MOVES)
		ft_close_game(data);
	return (0);
}
