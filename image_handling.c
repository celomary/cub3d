/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:56:49 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:23:33 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_img(t_map *map, int x, int y, int color)
{
	int		*data;
	int		line_size;
	int		k;

	data = (int *)mlx_get_data_addr(map->img_ptr, &k, &line_size, &k);
	if (x >= 0 && y >= 0 && x < map->res.x && y < map->res.y)
		data[x + y * (int)map->res.x] = color;
}

void	clear(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
}

void	display_img(t_map *map, void func(t_map *map))
{
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->res.x, map->res.y);
	func(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

void	refresh_window(t_map *map, void func(t_map *map))
{
	clear(map);
	display_img(map, func);
}
