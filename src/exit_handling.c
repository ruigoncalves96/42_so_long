/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:10:05 by randrade          #+#    #+#             */
/*   Updated: 2024/11/07 13:07:21 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_error(t_data *data)
{
	mlx_destroy_window(data->mlx.init, data->mlx.win);
	if (data->player.img.img != NULL)
		mlx_destroy_image(data->mlx.init, data->player.img.img);
	if (data->collect.img.img != NULL)
		mlx_destroy_image(data->mlx.init, data->collect.img.img);
	if (data->exit.img.img != NULL)
		mlx_destroy_image(data->mlx.init, data->exit.img.img);
	if (data->wall.img != NULL)
		mlx_destroy_image(data->mlx.init, data->wall.img);
	if (data->floor.img != NULL)
		mlx_destroy_image(data->mlx.init, data->floor.img);
	mlx_destroy_display(data->mlx.init);
	free(data->mlx.init);
	ft_fderror_free_exit(ERROR_LOAD_IMAGE_M, (char **)data->map);
}

void	ft_size_map_error(t_data *data)
{
	mlx_destroy_display(data->mlx.init);
	free(data->mlx.init);
	ft_fderror_free_exit(LARGE_MAP_M, (char **)data->map);
}

int	ft_close_game(t_data *data)
{
	if (data->moves >= MAX_MOVES)
		printf("You've reached the MAX moves possible\n");
	ft_free_array((char **)data->map);
	mlx_destroy_window(data->mlx.init, data->mlx.win);
	mlx_destroy_image(data->mlx.init, data->player.img.img);
	mlx_destroy_image(data->mlx.init, data->collect.img.img);
	mlx_destroy_image(data->mlx.init, data->exit.img.img);
	mlx_destroy_image(data->mlx.init, data->wall.img);
	mlx_destroy_image(data->mlx.init, data->floor.img);
	mlx_destroy_display(data->mlx.init);
	free(data->mlx.init);
	exit (0);
	return (0);
}
