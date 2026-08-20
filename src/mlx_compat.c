/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 12:00:00 by randrade          #+#    #+#             */
/*   Updated: 2026/08/20 12:00:00 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** The macOS MiniLibX provides neither mlx_destroy_display() — there is no X
** display to close — nor mlx_get_screen_size(). These wrappers keep the two
** platform differences in one place instead of spreading #ifdefs through the
** call sites.
*/

#ifdef SO_LONG_MAC

void	ft_mlx_destroy_display(void *mlx_ptr)
{
	(void)mlx_ptr;
}

void	ft_mlx_get_screen_size(void *mlx_ptr, int *screen_x, int *screen_y)
{
	(void)mlx_ptr;
	*screen_x = INT_MAX;
	*screen_y = INT_MAX;
}

#else

void	ft_mlx_destroy_display(void *mlx_ptr)
{
	mlx_destroy_display(mlx_ptr);
}

void	ft_mlx_get_screen_size(void *mlx_ptr, int *screen_x, int *screen_y)
{
	mlx_get_screen_size(mlx_ptr, screen_x, screen_y);
}

#endif
