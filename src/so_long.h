/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:50 by randrade          #+#    #+#             */
/*   Updated: 2024/10/31 11:42:54 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
# include "../Library/get_next_line/get_next_line.h"
//# include "../mlx_linux/mlx.h"	//	LINUX
# include "../mlx/mlx.h"		//	MAC
# include <stdbool.h>
# include <string.h>

# define WRONG_FORMAT_M "Error\nDescription: Wrong format!\n"
# define NOT_BER_M "Error\nDescription: Not a *.ber file!\n"
# define EMPTY_M "Error\nDescription: Empty file!\n"
# define NOT_RECTANGLE_M "Error\nDescription: Map not rectangle!\n"
# define NOT_CLOSED_M "Error\nDescription: Map not closed!\n"
# define WRONG_CONTENT_M "Error\nDescription: Not the right content!\n"
# define NOT_WINNABLE_M "Error\nDescription: Not winnable!\n"

typedef struct s_coord
{
	unsigned int	y;
	unsigned int	x;
}		t_coord;

typedef struct s_map_info
{
	unsigned int	walls;
	unsigned int	floors;
	unsigned int	player;
	unsigned int	collectibles;
	unsigned int	exit;
	bool		exit_reached;
	bool		collectibles_reached;
	t_coord			size;
	t_coord			player_coord;
}		t_map_info;

typedef struct s_mlx
{
	void	*init;
	void	*win;
}		t_mlx;

typedef struct s_image
{
	void	*img;
	char	*path;
	int	width;
	int	height;
}		t_image;

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
bool	ft_count_content(char content, t_map_info *map_info,
			unsigned int y, unsigned int x);
bool	ft_check_top_bottom_wall(const char *map, t_map_info *map_info);
bool	ft_check_left_right_wall(const char *map, t_map_info *map_info);
unsigned int	ft_flood_fill(char **map, t_map_info *map_info,
			unsigned int y, unsigned int x);

//	CHECK_FILE
bool	ft_is_file_readable(const char *file);

//	ALLOC_MAP
char	**ft_alloc_map_array(const char *map, t_map_info *map_info);

//	MAP_PARSING
bool	ft_map_parsing(const char **map, t_map_info *map_info);

//	
void	ft_window(const char **map, t_map_info *map_info);

#endif
