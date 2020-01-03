/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:18:05 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:08:58 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		to_radian(float deg)
{
	return ((deg * M_PI) / 180.0);
}

float		to_degree(float radian)
{
	return ((radian * 180.0) / M_PI);
}

int			get_offset(t_map *map, char c, int x, int y)
{
	if (c == 'v')
		return (y % (int)(map->grid.x));
	return (x % (int)(map->grid.x));
}

t_vector	init_vector(float x, float y)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
}

void		free_gnl(int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
		free(line);
}
