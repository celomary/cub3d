/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:08:37 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:59:31 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_keys(t_map *map)
{
	map->keys[0] = -1;
	map->keys[1] = -1;
	map->keys[2] = -1;
	map->keys[3] = -1;
}

int				init_map(t_map *map, char *filename)
{
	map->mlx_ptr = mlx_init();
	if (get_info(map, filename))
		return (1);
	if (check_map(map))
	{
		ft_putstr("invalid map :)\n");
		return (1);
	}
	map->win_ptr = mlx_new_window(map->mlx_ptr,
	map->res.x, map->res.y, "CUB3D");
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->res.x, map->res.y);
	map->grid.x = 256;
	map->grid.y = 256;
	map->updown = 0;
	if (get_player_pos(map))
		return (1);
	init_keys(map);
	return (0);
}
