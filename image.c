/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:57:24 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:29:27 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image(t_map *map)
{
	map->player.cos_p = cos(to_radian(map->player.theta));
	map->player.sin_p = sin(to_radian(map->player.theta));
	view3d(map);
	draw_map2d(map);
	draw_player2d(map);
}
