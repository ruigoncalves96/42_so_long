/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:25:53 by randrade          #+#    #+#             */
/*   Updated: 2024/10/29 22:32:09 by randrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	PERROR + EXIT
void	ft_perror_exit(void)
{
	perror("Exit\nDescription");
	exit(1);
}

//	PERROR + FREE_ARRAY + EXIT
void	ft_perror_free_exit(char **array)
{
	perror("Exit\nDescription");
	ft_free_array(array);
	exit(1);
}

//	ERROR_MESSAGE + EXIT
void	ft_fderror_exit(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(1);
}

//	ERROR_MESSAGE + FREE_ARRAY + EXIT
void	ft_fderror_free_exit(char *error_message, char **array)
{
	ft_putstr_fd(error_message, 2);
	ft_free_array(array);
	exit(1);
}
