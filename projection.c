/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:04:22 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:26:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		actual_height(t_map *map, float distance, float o)
{
	float	distance_toprojplane;
	float	wallproj;
	float	distance_to_ray;

	distance_to_ray = distance * cos(to_radian(o));
	distance_toprojplane = (map->res.x / 2.0) / 1.09696607994;
	wallproj = (map->grid.x * distance_toprojplane) / distance_to_ray;
	return (wallproj);
}

float		start_y(t_map *map, float height)
{
	float	start;

	start = (map->res.y - height) / 2;
	return (start);
}
