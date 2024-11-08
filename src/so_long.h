/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <randrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:50 by randrade          #+#    #+#             */
/*   Updated: 2024/11/08 13:29:36 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Library/libft/libft.h"
# include "../Library/ft_printf/ft_printf.h"
# include "../Library/get_next_line/get_next_line.h"
# include "../minilibx/mlx_linux/mlx.h"
# include <stdbool.h>
# include <string.h>

# define WRONG_FORMAT_M "Error\nDescription: Wrong format!\n"
# define NOT_BER_M "Error\nDescription: Not a *.ber file!\n"
# define EMPTY_M "Error\nDescription: Empty file!\n"
# define NOT_RECTANGLE_M "Error\nDescription: Map not rectangle!\n"
# define NOT_CLOSED_M "Error\nDescription: Map not closed!\n"
# define WRONG_CONTENT_M "Error\nDescription: Not the right content!\n"
# define NOT_WINNABLE_M "Error\nDescription: Not winnable!\n"
# define ERROR_LOAD_IMAGE_M "Error\nDescription: Failed to load image!\n"
# define LARGE_MAP_M "Error\nDescription: Map too large!\n"

# define WALL_PATH "textures/42_64x64/rock.xpm"
# define FLOOR_PATH "textures/42_64x64/water.xpm"
# define COLLECT_PATH "textures/42_64x64/42.xpm"
# define PLAYER_PATH "textures/42_64x64/duck.xpm"
# define EXIT_PATH "textures/42_64x64/blackhole.xpm"

# define IMG_RES 64

# define ESC 65307
# define LEFT_A 97
# define RIGHT_D 100
# define DOWN_S 115
# define UP_W 119
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define UP_ARROW 65362

# define MAX_MOVES 4294967295

typedef struct s_coord
{
	unsigned int	y;
	unsigned int	x;
}					t_coord;

typedef struct s_mlx
{
	void			*init;
	void			*win;
}					t_mlx;

typedef struct s_image
{
	void			*img;
	char			*path;
	int				width;
	int				height;
}					t_image;

typedef struct s_player
{
	t_image			img;
	t_coord			coord;
}					t_player;

typedef struct s_collect
{
	unsigned int	count;
	t_image			img;
}					t_collect;

typedef struct s_exit
{
	t_image			img;
	bool			is_open;
}					t_exit;

typedef struct s_map_info
{
	unsigned int	player;
	unsigned int	collectibles;
	unsigned int	exit;
	bool			exit_reached;
	bool			collectibles_reached;
	t_coord			size;
}					t_map_info;

typedef struct s_data
{
	const char		**map;
	unsigned int	moves;
	t_mlx			mlx;
	t_player		player;
	t_collect		collect;
	t_exit			exit;
	t_image			wall;
	t_image			floor;
	t_map_info		map_info;
}					t_data;

//	ERROR_HANDLING
void				ft_perror_exit(void);
void				ft_perror_free_exit(char **array);
void				ft_fderror_exit(char *error_message);
void				ft_fderror_free_exit(char *error_message, char **array);

//	EXIT_HANDLING
void				ft_image_error(t_data *data);
void				ft_size_map_error(t_data *data);
int					ft_close_game(t_data *data);

//	UTILS
char				**ft_array_dup(const char **map, t_map_info *map_info);
void				ft_initialize_t_data(t_data *data);
void				ft_free_array(char **array);

//	PARSING_UTILS
bool				ft_count_content(char content, t_data *data, unsigned int y,
						unsigned int x);
bool				ft_check_top_bottom_wall(const char *map,
						t_map_info *map_info);
bool				ft_check_left_right_wall(const char *map,
						t_map_info *map_info);
unsigned int		ft_flood_fill(char **map, t_map_info *map_info,
						unsigned int y, unsigned int x);

//	RUN_GAME_UTILS
void				ft_print_moves(t_data *data);
void				ft_update_player_position(char **map, t_data *data,
						unsigned int y, unsigned int x);
void				ft_check_screen_map_size(t_data *data);

//	CHECK_FILE
bool				ft_is_file_readable(const char *file);

//	ALLOC_MAP
char				**ft_alloc_map_array(const char *map, t_map_info *map_info);

//	MAP_PARSING
bool				ft_map_parsing(t_data *data);

//	KEY_HANDLER
int					ft_key_handler(int keycode, t_data *data);

//	DRAW_MAP
void				ft_draw_map(t_data *data);

#endif

/*
 
- INCLUDE MAC -

# include "../minilibx/mlx/mlx.h"

- KEYS FOR MAC -

# define ESC 53
# define LEFT_A 0
# define RIGHT_D 2
# define DOWN_S 1
# define UP_W 13
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

- NALA TEXTURES -

# define WALL_PATH "textures/Nala_32x32/tree.xpm"
# define FLOOR_PATH "textures/Nala_32x32/grass.xpm"
# define COLLECT_PATH "textures/Nala_32x32/ball.xpm"
# define PLAYER_PATH "textures/Nala_32x32/nala.xpm"
# define EXIT_PATH "textures/Nala_32x32/portal.xpm"

- 42 TEXTURES -

# define WALL_PATH "textures/42_64x64/rock.xpm"
# define FLOOR_PATH "textures/42_64x64/water.xpm"
# define COLLECT_PATH "textures/42_64x64/42.xpm"
# define PLAYER_PATH "textures/42_64x64/duck.xpm"
# define EXIT_PATH "textures/42_64x64/blackhole.xpm"

- PIRATE TEXTURES -

# define WALL_PATH "textures/Pirate_64x64/water.xpm"
# define FLOOR_PATH "textures/Pirate_64x64/wood_water.xpm"
# define COLLECT_PATH "textures/Pirate_64x64/donut.xpm"
# define PLAYER_PATH "textures/Pirate_64x64/pirate.xpm"
# define EXIT_PATH "textures/Pirate_64x64/portal.xpm"

*/
