/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:00:21 by randrade          #+#    #+#             */
/*   Updated: 2024/10/31 14:26:48 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(const char **map, t_map_info *map_info)
{
	t_mlx	mlx;
	t_image	img;
	(void)map;
	(void)map_info;
	int     img_width;
	int     img_height;

	mlx.init = mlx_init();
	mlx.win= mlx_new_window(mlx.init, 1920, 1080, "so_long");
	img.img = mlx_xpm_file_to_image(mlx.init, "textures/nala.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx.init, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.init);
}
