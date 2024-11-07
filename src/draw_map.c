/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/11/07 14:07:09 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_load_images(t_data *data)
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
	if (data->player.img.img == NULL || data->collect.img.img == NULL
		|| data->exit.img.img == NULL || data->wall.img == NULL
		|| data->floor.img == NULL)
		ft_image_error(data);
}

static void	ft_draw_element(t_mlx *mlx, t_image *img, int x, int y)
{
	mlx_put_image_to_window(mlx->init, mlx->win, img->img, x * IMG_RES,
		y * IMG_RES);
}

void	ft_draw_map(t_data *data)
{
	unsigned int	y;
	unsigned int	x;

	ft_load_images(data);
	y = 0;
	while (y < data->map_info.size.y)
	{
		x = 0;
		while (x < data->map_info.size.x)
		{
			if (data->map[y][x] == '1')
				ft_draw_element(&data->mlx, &data->wall, x, y);
			else if (data->map[y][x] == '0')
				ft_draw_element(&data->mlx, &data->floor, x, y);
			else if (data->map[y][x] == 'P')
				ft_draw_element(&data->mlx, &data->player.img, x, y);
			else if (data->map[y][x] == 'C')
				ft_draw_element(&data->mlx, &data->collect.img, x, y);
			else if (data->map[y][x] == 'E')
				ft_draw_element(&data->mlx, &data->exit.img, x, y);
			x++;
		}
		y++;
	}
}
