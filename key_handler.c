/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 22:58:02 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:59:39 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pressed_key(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 13 || key == 1)
		map->keys[0] = key;
	if (key == 0 || key == 2)
		map->keys[1] = key;
	if (key == 123 || key == 124)
		map->keys[2] = key;
	if (key == 126 || key == 125)
		map->keys[3] = key;
	return (0);
}

int		realease_key(int key, void *param)
{
	t_map *map;

	map = (t_map *)param;
	if (key == 13 || key == 1)
		map->keys[0] = -1;
	if (key == 0 || key == 2)
		map->keys[1] = -1;
	if (key == 123 || key == 124)
		map->keys[2] = -1;
	if (key == 126 || key == 125)
		map->keys[3] = -1;
	return (0);
}
