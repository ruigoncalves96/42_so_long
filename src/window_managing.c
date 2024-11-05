/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 14:31:35 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_elements(t_data *data, t_image *img, char c)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < data->map_info.size.y)
	{
		x = 0;
		while (x < data->map_info.size.x)
		{
			if (data->map[y][x] == c)
				mlx_put_image_to_window(data->mlx.init, data->mlx.win, img->img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_put_floor(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < data->map_info.size.y)
	{
		x = 0;
		while (x < data->map_info.size.x)
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

	y = data->player.coord.y;
	x = data->player.coord.x;
	if (data->map[y][x - 1] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player.coord.x -= 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img, data->player.coord.x * 32, data->player.coord.y * 32);
}

void	ft_move_player_right(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player.coord.y;
	x = data->player.coord.x;
	if (data->map[y][x + 1] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player.coord.x += 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img, data->player.coord.x * 32, data->player.coord.y * 32);
}

void	ft_move_player_down(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player.coord.y;
	x = data->player.coord.x;
	if (data->map[y + 1][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player.coord.y += 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img, data->player.coord.x * 32, data->player.coord.y * 32);
}

void	ft_move_player_up(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = data->player.coord.y;
	x = data->player.coord.x;
	if (data->map[y - 1][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, x * 32, y * 32);
	data->player.coord.y -= 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player.coord.x * 32, data->player.coord.y * 32);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img, data->player.coord.x * 32, data->player.coord.y * 32);
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

void	ft_window(t_data *data)
{
	data->mlx.init = mlx_init();
	data->mlx.win= mlx_new_window(data->mlx.init, (data->map_info.size.x * 32), (data->map_info.size.y * 32), "so_long");
	data->floor.img = mlx_xpm_file_to_image(data->mlx.init, "textures/grass.xpm", &data->floor.width, &data->floor.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx.init, "textures/tree.xpm", &data->wall.width, &data->wall.height);
	data->collect.img.img = mlx_xpm_file_to_image(data->mlx.init, "textures/ball.xpm", &data->collect.img.width, &data->collect.img.height);
	data->player.img.img = mlx_xpm_file_to_image(data->mlx.init, "textures/nala.xpm", &data->player.img.width, &data->player.img.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx.init, "textures/portal.xpm", &data->exit.width, &data->exit.height);
	ft_put_floor(data);
	ft_put_elements(data, &data->wall, '1');
	ft_put_elements(data, &data->collect.img, 'C');
	ft_put_elements(data, &data->exit, 'E');
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img, (int)data->player.coord.x * 32, (int)data->player.coord.y * 32);
	mlx_key_hook(data->mlx.win, ft_key, data);
	mlx_loop(data->mlx.init);
}
