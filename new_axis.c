/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:12:19 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:37:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float			new_x(t_map *map, t_vector old)
{
	float	x;

	x = (map->player.x + (old.x - map->player.x) * map->player.cos_p -
	(old.y - map->player.y) * map->player.sin_p);
	return (x);
}

float			new_y(t_map *map, t_vector old)
{
	float	y;

	y = map->player.y + (old.x - map->player.x) * map->player.sin_p
		+ (old.y - map->player.y) * map->player.cos_p;
	return (y);
}

t_vector		point_axis(t_map *map, t_vector point, float o)
{
	t_vector	new;
	float		cos_o;
	float		sin_o;

	cos_o = cos(to_radian(o));
	sin_o = sin(to_radian(o));
	new.x = map->player.x + (point.x - map->player.x)
	* cos_o - (point.y - map->player.y) * sin_o;
	new.y = map->player.y + (point.x - map->player.x)
	* sin_o + (point.y - map->player.y) * cos_o;
	return (new);
}
