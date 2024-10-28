/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:50 by randrade          #+#    #+#             */
/*   Updated: 2024/10/28 14:32:27 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
# include "../Library/get_next_line/get_next_line.h"
//# include "../mlx/mlx.h"
# include <stdbool.h>
# include <string.h>

# define WRONG_FORMAT_M "Error\nDescription: Wrong format!\n< ./so_long <filename>.ber >\n"
# define NOT_BER_M "Error\nDescription: Not a *.ber file!\n"

typedef struct	s_coord
{
	unsigned int	x;
	unsigned int	y;
}		t_coord;

typedef struct	s_map_info
{
	unsigned int	size_x;
	unsigned int	size_y;
	unsigned int	wall;
	unsigned int	floor;
	unsigned int	player;
	t_coord	player_coord;
	unsigned int	collectible;
	unsigned int	exit;
}		t_map_info;

//	ERROR HANDLING
void	ft_perror_exit(void);
void	ft_perror_free_exit(char **array);
void	ft_fderror_exit(char *error_message);
void	ft_fderror_free_exit(char *error_message, char **array);
	
//	UTILS
char	**ft_array_dup(const char **map, t_map_info *map_info);
void	ft_initialize_t_map_info(t_map_info *map_info);
void	ft_print_array(const char **str);
void	ft_free_array(char **array);

//	PARSING_UTILS
bool	ft_is_winnable(const char **map);
void	ft_flood_fill(char **map, t_map_info *map_info, unsigned int x, unsigned int y);
bool	ft_count_content(char content, t_map_info *map_info, unsigned int x, unsigned y);
bool	ft_check_top_bottom_wall(const char *map, t_map_info *map_info);
bool	ft_check_left_right_wall(const char *map, t_map_info *map_info);

//	CHECK_FILE
bool	ft_is_file_readable(const char *file);

//	ALLOC_MAP
char	**ft_alloc_map_array(const char *map, t_map_info *map_info);

//	MAP_PARSING
bool	ft_map_parsing(const char **map, t_map_info *map_info);

#endif
