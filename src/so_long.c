/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:10 by randrade          #+#    #+#             */
/*   Updated: 2024/10/24 17:29:58 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		// PRINT ERROR;
		return (1);
	}
	// CHECK MAP FILE
	if (ft_check_file(argv[1]) == true)
		ft_printf("GOOD FILE\n");
	//ft_map_parsing(argv[1]);
	// PARSING MAP
	// 	- IS RETANGULAR? ** all lines should have same lenght **
	// 	- CHECK EXTRA STUFF IN THE MAP
}
