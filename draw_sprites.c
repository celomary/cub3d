/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:34:17 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:52:37 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tuple		*find_sprite_distance(t_map *map, t_vector *axis,
t_vector *horizental, t_vector *vertical)
{
	t_tuple		*p_dis;
	t_vector	*hor;
	t_vector	*ver;

	hor = horizental + ((map->x_inter < 0) ? 4 : map->x_inter);
	ver = vertical + ((map->y_inter < 0) ? 4 : map->y_inter);
	p_dis = get_small_distance(axis, hor, ver);
	return (p_dis);
}

static int			check_wall(t_tuple **sdist, float wall_dis)
{
	if ((*sdist)->b >= wall_dis)
	{
		free(*sdist);
		return (0);
	}
	return (1);
}

void				draw_sprites(t_map *map, t_vector *horizental,
t_vector *vertical, t_sprite_params params)
{
	t_tuple		*sprite_distance;
	t_vector	old_axis;

	old_axis = player_axis(map->player);
	while (--map->x_inter >= 0 || --map->y_inter >= 0)
	{
		sprite_distance = find_sprite_distance(map, &old_axis,
		horizental, vertical);
		if (!check_wall(&sprite_distance, params.dist))
			continue ;
		draw_sprite(map, sprite_distance, params.x, params.o);
		free(sprite_distance);
	}
}
