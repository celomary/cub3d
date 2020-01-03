/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intercept.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:03:12 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 23:43:30 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			is_wall_v(t_vector *point, t_map *map, float o)
{
	float	limit_x;
	float	limit_y;

	limit_x = (map->grid.x - 1) * map->x_table;
	limit_y = (map->grid.y - 1) * map->y_table;
	if (point->x < 0 || point->x >= limit_x
	|| point->y < 0 || point->y >= limit_y)
	{
		point->x = -10000000;
		point->y = -10000000;
		return (1);
	}
	if (map->str_map[(int)((point->y) / map->grid.y)]
	[(int)((point->x) / map->grid.x) +
	((!(o > 270 || (o >= 0 && o < 90))) ? -1 : 0)] == '1')
		return (1);
	return (0);
}

static void			get_next_point(t_vector *point, t_vector step)
{
	point->x += step.x;
	point->y -= step.y;
}

static void			find_step(t_map *map, t_vector *step, float o)
{
	if (o > 270 || (o >= 0 && o < 90))
		step->x = map->grid.x;
	else
		step->x = -map->grid.x;
	step->y = step->x * tan(-to_radian(o));
}

static t_vector		*init_ver_point(void)
{
	t_vector	*init;
	int			iter;

	init = malloc(sizeof(t_vector) * 5);
	iter = -1;
	while (++iter < 5)
	{
		init[iter].x = 1000000000;
		init[iter].y = 1000000000;
	}
	return (init);
}

t_vector			*get_vertical_point(t_map *map, float x, float y, float o)
{
	t_vector	point_a;
	t_vector	step;
	t_vector	*ver_point;
	int			isr;

	ver_point = init_ver_point();
	isr = (o > 270 || (o >= 0 && o < 90));
	point_a.x = floor(x / map->grid.x) * map->grid.x + (isr ? map->grid.x : 0);
	point_a.y = y + (x - point_a.x) * tan(-to_radian(o));
	find_step(map, &step, o);
	map->y_inter = 0;
	while (!is_wall_v(&point_a, map, o))
	{
		if (map->str_map[(int)((point_a.y) / map->grid.y)]
		[(int)((point_a.x) / map->grid.x) + (!isr ? -1 : 0)] == '2')
		{
			ver_point[map->y_inter].x = point_a.x + (!isr ? -1 : 0);
			ver_point[map->y_inter].y = point_a.y;
			map->y_inter++;
		}
		get_next_point(&point_a, step);
	}
	ver_point[map->y_inter].y = point_a.y;
	ver_point[map->y_inter].x = point_a.x;
	return (ver_point);
}
