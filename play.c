/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:41:16 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 22:26:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		play(char *fname)
{
	t_map	map;

	if (init_map(&map, fname))
		return ;
	image(&map);
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.img_ptr, 0, 0);
	mlx_hook(map.win_ptr, 2, 0, pressed_key, &map);
	mlx_hook(map.win_ptr, 3, 0, realease_key, &map);
	mlx_loop_hook(map.mlx_ptr, move_player, &map);
	system("afplay sound/s.mp3 -t 0.00000001 -v 5");
	mlx_loop(map.mlx_ptr);
}
