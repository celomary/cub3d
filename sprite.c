/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:45:35 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 22:50:14 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_center2(t_map *map, float x, float y)
{
	t_vector center;

	center.x = floor(x / map->grid.x) * map->grid.x + map->grid.x / 2;
	center.y = floor(y / map->grid.y) * map->grid.y + map->grid.y / 2;
	return (center);
}

t_vector	get_point(t_map *map, t_vector center, float x, float y)
{
	t_vector	vect;
	float		cp;
	float		sp;
	float		o;

	cp = atan2(center.y - map->player.y, center.x - map->player.x);
	sp = atan2(y - map->player.y, x - map->player.x);
	o = sp - cp;
	vect = point_axis(map, center, to_degree(o));
	return (vect);
}

float		find_offset(t_map *map, t_vector center, t_vector point, float o)
{
	t_vector	vect;
	float		theta;

	theta = atan2(center.y - map->player.y, center.x - map->player.x);
	vect.x = center.x + (map->grid.x / 2.0) * cos(theta - to_radian(90));
	vect.y = center.y + (map->grid.x / 2.0) * sin(theta - to_radian(90));
	return (sqrt(pow(point.x - vect.x, 2) + pow(point.y - vect.y, 2)));
}

void		sprite_helper(t_map *map, float offset, float distance,
t_vector x_o)
{
	float	height;
	float	start;
	float	iter;
	int		color;

	height = actual_height(map, distance, x_o.y);
	start = start_y(map, height);
	iter = start - 1;
	while (++iter - start < height)
	{
		color = get_sprite_color(map, offset, height, iter - start);
		if (color > 0x000000)
			put_pixel_img(map, x_o.x, map->updown + iter,
			shading_color(color, distance / 640));
	}
}

void		draw_sprite(t_map *map, t_tuple *dis_b, int x, float o)
{
	t_vector		center;
	t_vector		point;
	float			distance;
	float			offset;

	center = get_center2(map, dis_b->x, dis_b->y);
	point = get_point(map, center, dis_b->x, dis_b->y);
	offset = find_offset(map, center, point, o);
	distance = get_distance(player_axis(map->player), point);
	if (get_distance(point, center) > map->grid.x / 2 - 18.5)
		return ;
	point.x = x;
	point.y = o;
	sprite_helper(map, offset, distance, point);
}
