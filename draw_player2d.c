/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:01:11 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:32:48 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_square(t_map *map, int color)
{
	t_vector	old_axis;

	old_axis.y = (map->player.y - 75);
	while (old_axis.y < map->player.y + 75)
	{
		old_axis.x = (map->player.x - 75);
		while (old_axis.x < map->player.x + 75)
		{
			put_pixel_img(map, new_x(map, old_axis) / 16,
					new_y(map, old_axis) / 16, color);
			old_axis.x++;
		}
		old_axis.y++;
	}
}

void			draw_line(t_map *map, float o, float x, float y)
{
	float	cos_o;
	float	sin_o;

	cos_o = cos(to_radian(o));
	sin_o = sin(to_radian(o));
	while (map->str_map[(int)((16 * y) / map->grid.y)]
	[(int)((x * 16) / map->grid.x)] != '1' &&
	map->str_map[(int)((16 * y) / map->grid.y)]
			[(int)((x * 16) / map->grid.x)] != '2')
	{
		put_pixel_img(map, x, y, 0xeedd82);
		x += cos_o;
		y += sin_o;
	}
}

void			draw_view(t_map *map, float x, float y)
{
	float	o;
	float	step;

	o = -30;
	step = 60.0 / map->res.x;
	while (o < 30)
	{
		draw_line(map, map->player.theta + o, x, y);
		o += step;
	}
}

void			draw_player2d(t_map *map)
{
	draw_view(map, map->player.x / 16, map->player.y / 16);
	draw_square(map, 0xFF8D79);
}
