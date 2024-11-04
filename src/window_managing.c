/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/04 15:31:33 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_elements(const char **map, t_map_info *map_info, t_data *data, t_image *img, char c)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map_info->size.y)
	{
		x = 0;
		while (x < map_info->size.x)
		{
			if (map[y][x] == c)
				mlx_put_image_to_window(data->mlx.init, data->mlx.win, img->img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_put_floor(const char **map, t_map_info *map_info, t_data *data, t_image *img_floor)
{
	(void)map;
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map_info->size.y)
	{
		x = 0;
		while (x < map_info->size.x)
		{
			mlx_put_image_to_window(data->mlx.init, data->mlx.win, img_floor->img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_move_player_left(t_data *data)
{
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->floor.img, data->player_c.x * 32, data->player_c.y * 32);
	data->player_c.x -= 1;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img, data->player_c.x * 32, data->player_c.y * 32);
}

int	ft_key(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	if (keycode == 123 || keycode == 0)
	{
		ft_printf("left\n");
		ft_move_player(data);
	}
	else if (keycode == 124 || keycode == 2)
		ft_printf("right\n");
	else if (keycode == 125 || keycode == 1)
		ft_printf("down\n");
	else if (keycode == 126 || keycode == 13)
		ft_printf("up\n");
	else if (keycode == 53)
		exit (0);
	else
		ft_printf("%d\n", keycode);
	return (0);
}

void	ft_window(const char **map, t_map_info *map_info)
{
	(void)map;
	t_data	data;

	data.player_c.y = map_info->player_c.y;
	data.player_c.x = map_info->player_c.x;
	data.mlx.init = mlx_init();
	data.mlx.win= mlx_new_window(data.mlx.init, (map_info->size.x * 32), (map_info->size.y * 32), "so_long");
	data.floor.img = mlx_xpm_file_to_image(data.mlx.init, "textures/grass.xpm", &data.floor.width, &data.floor.height);
	data.wall.img = mlx_xpm_file_to_image(data.mlx.init, "textures/tree.xpm", &data.wall.width, &data.wall.height);
	data.collect.img = mlx_xpm_file_to_image(data.mlx.init, "textures/ball.xpm", &data.collect.width, &data.collect.height);
	data.player.img = mlx_xpm_file_to_image(data.mlx.init, "textures/nala.xpm", &data.player.width, &data.player.height);
	data.exit.img = mlx_xpm_file_to_image(data.mlx.init, "textures/portal.xpm", &data.exit.width, &data.exit.height);
	ft_put_floor(map, map_info, &data, &data.floor);
	ft_put_elements(map, map_info, &data, &data.wall, '1');
	ft_put_elements(map, map_info, &data, &data.collect, 'C');
	ft_put_elements(map, map_info, &data, &data.exit, 'E');
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, data.player.img, (int)map_info->player_c.x * 32, (int)map_info->player_c.y * 32);
	mlx_key_hook(data.mlx.win, ft_key, &data);
	mlx_loop(data.mlx.init);
}
