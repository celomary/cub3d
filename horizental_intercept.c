/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizental_intercept.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:33:00 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:13:22 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			is_wall_h(t_vector *point, t_map *map, float o)
{
	float	limit_x;
	float	limit_y;

	limit_x = (map->grid.x - 1) * map->x_table - 1;
	limit_y = (map->grid.y - 1) * map->y_table - 1;
	if (point->x < 0 || point->x >= limit_x ||
	point->y < 0 || point->y >= limit_y)
	{
		point->x = -100000;
		point->y = -100000;
		return (1);
	}
	if (map->str_map[(int)((point->y) / map->grid.y) -
	((o >= 180 || o == 0) ? 1 : 0)][(int)((point->x) / map->grid.x)] == '1')
		return (1);
	return (0);
}

static void			get_next_point_h(t_vector *point, t_vector step)
{
	point->y += step.y;
	point->x -= step.x;
}

static void			find_step(t_map *map, t_vector *step, float o)
{
	if (o >= 180 || o == 0)
		step->y = -map->grid.y;
	else
		step->y = map->grid.x;
	step->x = step->y / tan(-to_radian(o));
}

static t_vector		*init_hor_points(void)
{
	t_vector	*vect;
	int			iter;

	vect = malloc(sizeof(t_vector) * 5);
	iter = -1;
	while (++iter < 5)
	{
		vect[iter].x = 100000000;
		vect[iter].y = 100000000;
	}
	return (vect);
}

t_vector			*get_horizental_point(t_map *map, float x, float y, float o)
{
	t_vector	point_a[2];
	t_vector	*point_h_inter;
	int			isd;

	isd = (o >= 180 || o == 0);
	point_h_inter = init_hor_points();
	point_a[0].y = floor((y / map->grid.y)) * map->grid.y +
	(isd ? 0 : map->grid.y);
	point_a[0].x = x + (y - point_a[0].y) / tan(-to_radian(o));
	find_step(map, &point_a[1], o);
	map->x_inter = 0;
	while (!is_wall_h(&point_a[0], map, o))
	{
		if (map->str_map[(int)((point_a[0].y) / map->grid.y) - (isd ? 1 : 0)]
		[(int)((point_a[0].x) / map->grid.x)] == '2')
		{
			point_h_inter[map->x_inter].x = point_a[0].x;
			point_h_inter[map->x_inter].y = point_a[0].y - ((isd) ? 1 : 0);
			map->x_inter++;
		}
		get_next_point_h(&point_a[0], point_a[1]);
	}
	point_h_inter[map->x_inter].x = point_a[0].x;
	point_h_inter[map->x_inter].y = point_a[0].y;
	return (point_h_inter);
}
