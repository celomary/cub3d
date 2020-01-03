/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:10:56 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 19:05:19 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_ray(t_map *map, float height, float x, t_tuple *tup)
{
	float		iter;
	float		start;
	int			color;

	start = start_y(map, height) + map->updown;
	iter = 0;
	while (iter < start)
	{
		put_pixel_img(map, x, iter, map->ciel_color);
		iter++;
	}
	while (iter - start < height)
	{
		if ((color = get_pixel_from_img(map, tup, height, iter - start)) != 0)
			put_pixel_img(map, x, iter, shading_color(color, tup->b / 640));
		iter++;
	}
	while (iter < map->res.y)
	{
		put_pixel_img(map, x, iter, map->floor_color);
		iter++;
	}
}

static void			wall_printer(t_map *map, int x, t_tuple **tup, float o)
{
	float	height;

	(*tup)->o = modulo(map->player.theta + o);
	height = actual_height(map, (*tup)->b, o);
	draw_ray(map, height, x, *tup);
	free(*tup);
}

t_vector			player_axis(t_player player)
{
	t_vector	vect;

	vect.x = player.x;
	vect.y = player.y;
	return (vect);
}

static void			draw_wallsprites(t_map *map, int x, float o)
{
	t_vector			*hor;
	t_vector			*ver;
	t_vector			axis;
	t_tuple				*p_dis;
	t_sprite_params		params;

	axis = player_axis(map->player);
	hor = get_horizental_point(map, new_x(map, axis),
	new_y(map, axis), modulo(o + map->player.theta));
	ver = get_vertical_point(map, new_x(map, axis), new_y(map, axis),
	modulo(o + map->player.theta));
	p_dis = get_small_distance(&axis, hor + map->x_inter, ver + map->y_inter);
	params.dist = p_dis->b;
	params.x = x;
	params.o = o;
	wall_printer(map, x, &p_dis, o);
	draw_sprites(map, hor, ver, params);
	free(hor);
	free(ver);
}

void				view3d(t_map *map)
{
	float		step;
	float		o;
	int			x;

	step = 60.0 / map->res.x;
	o = -30;
	x = -1;
	while (++x < map->res.x)
	{
		draw_wallsprites(map, x, o);
		o += step;
	}
}
