/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/04 17:26:02 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_elements(t_data *data, t_map_info *map_info, t_image *img, char c)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map_info->size.y)
	{
		x = 0;
		while (x < map_info->size.x)
		{
			if (data->map[y][x] == c)
				mlx_put_image_to_window(data->mlx.init, data->mlx.win, img->img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_put_floor(t_data *data, t_map_info *map_info)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map_info->size.y)
	{
		x = 0;
		while (x < map_info->size.x)
		{
			mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_move_player_left(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player_c.y;
	x = data->player_c.x;
	if (data->map[y][x - 1] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player_c.x -= 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player_c.x * 32, data->player_c.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, data->player_c.x * 32, data->player_c.y * 32);
}

void	ft_move_player_right(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player_c.y;
	x = data->player_c.x;
	if (data->map[y][x + 1] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player_c.x += 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player_c.x * 32, data->player_c.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, data->player_c.x * 32, data->player_c.y * 32);
}

void	ft_move_player_down(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player_c.y;
	x = data->player_c.x;
	if (data->map[y + 1][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player_c.y += 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player_c.x * 32, data->player_c.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, data->player_c.x * 32, data->player_c.y * 32);
}

void	ft_move_player_up(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player_c.y;
	x = data->player_c.x;
	if (data->map[y - 1][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player_c.y -= 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player_c.x * 32, data->player_c.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, data->player_c.x * 32, data->player_c.y * 32);
}

int	ft_key(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	if (keycode == 123 || keycode == 0)
		ft_move_player_left(data);
	else if (keycode == 124 || keycode == 2)
		ft_move_player_right(data);
	else if (keycode == 125 || keycode == 1)
		ft_move_player_down(data);
	else if (keycode == 126 || keycode == 13)
		ft_move_player_up(data);
	else if (keycode == 53)
		exit (0);
	return (0);
}

void	ft_window(t_data *data, t_map_info *map_info)
{
	data->player_c.y = map_info->player_c.y;
	data->player_c.x = map_info->player_c.x;
	data->mlx.init = mlx_init();
	data->mlx.win= mlx_new_window(data->mlx.init, (map_info->size.x * 32), (map_info->size.y * 32), "so_long");
	data->floor.img = mlx_xpm_file_to_image(data->mlx.init, "textures/grass.xpm", &data->floor.width, &data->floor.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx.init, "textures/tree.xpm", &data->wall.width, &data->wall.height);
	data->collect.img = mlx_xpm_file_to_image(data->mlx.init, "textures/ball.xpm", &data->collect.width, &data->collect.height);
	data->player.img = mlx_xpm_file_to_image(data->mlx.init, "textures/nala.xpm", &data->player.width, &data->player.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx.init, "textures/portal.xpm", &data->exit.width, &data->exit.height);
	ft_put_floor(data, map_info);
	ft_put_elements(data, map_info, &data->wall, '1');
	ft_put_elements(data, map_info, &data->collect, 'C');
	ft_put_elements(data, map_info, &data->exit, 'E');
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, (int)map_info->player_c.x * 32, (int)map_info->player_c.y * 32);
	mlx_key_hook(data->mlx.win, ft_key, data);
	mlx_loop(data->mlx.init);
}
