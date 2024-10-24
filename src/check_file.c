/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:34:07 by randrade          #+#    #+#             */
/*   Updated: 2024/10/24 17:47:12 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	ft_parsing_file_name(const char *file)
{
	char	*str;

	str = ft_strrchr(file, '.');
	if (str == NULL)
		return (false);
	str++;
	if (ft_strlen(str) > 3)
		return (false);
	if (ft_strncmp("ber", str, 3) != 0)
		return (false);
	return (true);
}

bool	ft_check_file(const char *file)
{
	int	fd;
	char	buffer[1];

	buffer[0] = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || read(fd, buffer, 1) == -1)
	{
		perror("Error\nDescription");
		close(fd);
		exit (1);
	}
	if (ft_parsing_file_name(file) == false)
	{
		ft_printf("Error\nDescription: Not a *.ber file\n");
		exit(1);
	}
	close(fd);
	return (true);
}
