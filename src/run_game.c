/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 16:44:52 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_elements(t_data *data, t_image *img, char c)
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
				mlx_put_image_to_window(data->mlx.init, data->mlx.win,
						img->img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

static void	ft_put_floor(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < data->map_info.size.y)
	{
		x = 0;
		while (x < data->map_info.size.x)
		{
			mlx_put_image_to_window(data->mlx.init, data->mlx.win,
					data->floor.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

static void	ft_draw_images(t_data *data)
{
	data->player.img.img = mlx_xpm_file_to_image(data->mlx.init, PLAYER_PATH,
			&data->player.img.width, &data->player.img.height);
	data->collect.img.img = mlx_xpm_file_to_image(data->mlx.init, COLLECT_PATH,
			&data->collect.img.width, &data->collect.img.height);
	data->exit.img.img = mlx_xpm_file_to_image(data->mlx.init, EXIT_PATH,
			&data->exit.img.width, &data->exit.img.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx.init, WALL_PATH,
			&data->wall.width, &data->wall.height);
	data->floor.img = mlx_xpm_file_to_image(data->mlx.init, FLOOR_PATH,
			&data->floor.width, &data->floor.height);
	if (data->player.img.img == NULL || data->collect.img.img == NULL || data->exit.img.img == NULL || data->wall.img == NULL || data->floor.img == NULL)
		ft_image_error(data);
	ft_put_floor(data);
	ft_put_elements(data, &data->wall, '1');
	ft_put_elements(data, &data->collect.img, 'C');
	ft_put_elements(data, &data->exit.img, 'E');
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->player.img.img,
			(int)data->player.coord.x * 32, (int)data->player.coord.y * 32);
}

void	ft_run_game(t_data *data)
{
	data->mlx.init = mlx_init();
	if (data->mlx.init == NULL)
		ft_perror_free_exit((char **)data->map);
	data->mlx.win = mlx_new_window(data->mlx.init, (data->map_info.size.x * 32),
			(data->map_info.size.y * 32), "so_long");
	if (data->mlx.win == NULL)
		ft_perror_free_exit((char **)data->map);
	ft_draw_images(data);
	mlx_key_hook(data->mlx.win, ft_key_handler, data);
	mlx_loop(data->mlx.init);
}
