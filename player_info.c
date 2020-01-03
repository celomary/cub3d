/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:26:17 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 23:46:55 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int		get_theta(char direction)
{
	if (direction == 'N')
		return (270);
	if (direction == 'S')
		return (90);
	if (direction == 'W')
		return (180);
	return (0);
}

static int		error_msg(int c)
{
	if (c > 1)
		ft_putstr("player duplicate :(\n");
	else
		ft_putstr("No player in map are you kidding me!\n");
	return (1);
}

int				get_player_pos(t_map *map)
{
	int x;
	int y;
	int	c;

	c = 0;
	y = -1;
	while (++y < map->y_table)
	{
		x = -1;
		while (++x < map->x_table)
		{
			if (is_player(map->str_map[y][x]))
			{
				map->player.x = x * map->grid.x + map->grid.x / 2;
				map->player.y = y * map->grid.y + map->grid.y / 2;
				map->player.theta = get_theta(map->str_map[y][x]);
				c++;
			}
		}
	}
	if (c != 1)
		return (error_msg(c));
	return (0);
}
