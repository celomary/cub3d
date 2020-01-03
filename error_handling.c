/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:08:18 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 13:07:34 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_filecub(char *file)
{
	int		iter;
	char	*cub;

	cub = ".cub";
	iter = 0;
	while (file[iter] != '\0')
	{
		if (*cub == '\0')
			break ;
		if (file[iter] == *cub)
			cub++;
		iter++;
	}
	if (*cub == '\0' && file[iter] == '\0')
		return (1);
	return (0);
}

int		notvalidfile(char *fname)
{
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}
