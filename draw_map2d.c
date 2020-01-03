/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:40:24 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:17:06 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_square(t_map *map, int x, int y, int color)
{
	int		i_x;
	int		i_y;

	i_y = y * 16;
	while (i_y < (y + 1) * 16)
	{
		i_x = x * 16;
		while (i_x < (x + 1) * 16)
		{
			put_pixel_img(map, i_x, i_y, color);
			i_x++;
		}
		i_y++;
	}
}

void		draw_map2d(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y_table)
	{
		x = 0;
		while (x < map->x_table)
		{
			if (map->str_map[y][x] == '1')
				put_square(map, x, y, 0x5E09E8);
			else if (map->str_map[y][x] == '2')
				put_square(map, x, y, 0xFFA52B);
			else if (map->str_map[y][x] != '1' || map->str_map[y][x] != '2')
				put_square(map, x, y, 0x18FFFD);
			x++;
		}
		y++;
	}
}
