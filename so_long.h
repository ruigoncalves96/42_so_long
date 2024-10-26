/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:50 by randrade          #+#    #+#             */
/*   Updated: 2024/10/26 18:34:36 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Library/libft/libft.h"
# include "./Library/ft_printf/ft_printf.h"
# include "./Library/get_next_line/get_next_line.h"
//# include "./mlx/mlx.h"
# include <stdbool.h>
# include <string.h>

typedef struct	s_map_info
{
	unsigned int	size_xy[2];
	unsigned int	wall;
	unsigned int	floor;
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	exit;
}		t_map_info;

typedef struct	s_coord
{
	unsigned int	x;
	unsigned int	y;
}		t_coord;

//	PARSING
bool	ft_is_file_readble(const char *file);
bool	ft_map_parsing(const char *map);

#endif
