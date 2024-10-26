/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/10/26 13:14:36 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error\nDescription: Wrong format! # './so_long *.ber'\n");
		return (1);
	}
	ft_is_file_readble(argv[1]);				// CHECK MAP FILE
	// PARSING MAP
	// 	- IS RETANGULAR? ** all lines should have same lenght **
	// 	- CHECK EXTRA STUFF IN THE MAP
	ft_map_parsing(argv[1]);
}
