/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:04:57 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 01:02:02 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_next_pos(t_map *map, float x, float y)
{
	map->player.x += x;
	map->player.y += y;
}

static int		is_availablemove(int *key)
{
	if (key[1] != -1 || key[0] != -1 || key[2] != -1 || key[3] != -1)
		return (1);
	return (0);
}

static void		look_updown(t_map *map, int key)
{
	if (key == 125 && map->updown > -400)
		map->updown -= 20;
	else if (key == 126 && map->updown < 400)
		map->updown += 20;
}

static int		check_border(t_map *map, int key, float cos_t, float sin_t)
{
	t_vector	vect;
	int			x;
	int			y;

	x = map->player.x;
	y = map->player.y;
	vect = player_axis(map->player);
	if (key == 13)
		vect = init_vector(x + 120 * cos_t, y + 120 * sin_t);
	else if (key == 1)
		vect = init_vector(x - 120 * cos_t, y - 120 * sin_t);
	else if (key == 0)
		vect = init_vector(x + 120 * sin_t, y - 120 * cos_t);
	else if (key == 2)
		vect = init_vector(x - 120 * sin_t, y + 120 * cos_t);
	return (map->str_map[(int)(vect.y / map->grid.y)]
	[(int)(vect.x / map->grid.x)]
			!= '1' && map->str_map[(int)(vect.y / map->grid.y)]
			[(int)(vect.x / map->grid.x)] != '2');
}

int				move_player(t_map *map)
{
	float	cos_o;
	float	sin_o;
	float	po;

	cos_o = map->player.cos_p;
	sin_o = map->player.sin_p;
	po = map->player.theta;
	if (map->keys[0] == 13 && check_border(map, map->keys[0], cos_o, sin_o))
		get_next_pos(map, 20 * cos_o, 20 * sin_o);
	else if (map->keys[0] == 1 && check_border(map, map->keys[0], cos_o, sin_o))
		get_next_pos(map, -20 * cos_o, -20 * sin_o);
	if (map->keys[1] == 0 && check_border(map, map->keys[1], cos_o, sin_o))
		get_next_pos(map, 20 * sin_o, -20 * cos_o);
	else if (map->keys[1] == 2 && check_border(map, map->keys[1], cos_o, sin_o))
		get_next_pos(map, -20 * sin_o, 20 * cos_o);
	if (map->keys[2] == 123)
		map->player.theta = modulo(map->player.theta - 3);
	else if (map->keys[2] == 124)
		map->player.theta = modulo(map->player.theta + 3);
	if (map->keys[3] == 125 || map->keys[3] == 126)
		look_updown(map, map->keys[3]);
	if (is_availablemove(map->keys))
		refresh_window(map, &image);
	return (0);
}
