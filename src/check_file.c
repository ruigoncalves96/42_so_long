/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:34:07 by randrade          #+#    #+#             */
/*   Updated: 2024/10/28 14:31:21 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

bool	ft_is_file_readable(const char *file)
{
	int	fd;
	char	buffer[1];

	buffer[0] = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || read(fd, buffer, 1) == -1)
		ft_perror_exit();
	if (ft_parsing_file_name(file) == false)
		ft_fderror_exit(NOT_BER_M);
	close(fd);
	return (true);
}
