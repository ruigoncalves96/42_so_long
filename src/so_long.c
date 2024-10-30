/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/10/30 12:34:07 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	** TEST MLX **
void	ft_window(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
*/
int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	const char	**map;

	if (argc != 2)
		ft_fderror_exit(WRONG_FORMAT_M);
	ft_is_file_readable(argv[1]);
	ft_initialize_t_map_info(&map_info);
	map = (const char **)ft_alloc_map_array(argv[1], &map_info);
	ft_map_parsing(map, &map_info);
	ft_print_array(map);
	ft_free_array((char **)map);
//	ft_window();
}
