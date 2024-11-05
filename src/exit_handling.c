/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:10:05 by randrade          #+#    #+#             */
/*   Updated: 2024/11/05 17:44:19 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	ERROR ON IMAGE (FREE IMAGE / ARRAY / WINDOW)
void	ft_image_error(t_data *data)
{
	ft_free_array((char **)data->map);
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
	exit (0);
}

int	ft_full_free(t_data *data)
{
	ft_free_array((char **)data->map);
	mlx_destroy_window(data->mlx.init, data->mlx.win);
	//free(data->mlx.win);
	//free(data->mlx.init);
	mlx_destroy_image(data->mlx.init, data->player.img.img);
	mlx_destroy_image(data->mlx.init, data->collect.img.img);
	mlx_destroy_image(data->mlx.init, data->exit.img.img);
	mlx_destroy_image(data->mlx.init, data->wall.img);
	mlx_destroy_image(data->mlx.init, data->floor.img);
//	free(data->player.img.img);
//	free(data->collect.img.img);
//	free(data->exit.img.img);
//	free(data->wall.img);
//	free(data->floor.img);
	exit (0);
	return (0);
}
