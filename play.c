/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:41:16 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/04 21:59:37 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		play(char *fname, char *save)
{
	t_map	map;

	if (init_map(&map, fname))
		return ;
	image(&map);
	if (save && comp_str("--save", save, 6))
		create_bmp(&map);
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.img_ptr, 0, 0);
	mlx_hook(map.win_ptr, 2, 0, pressed_key, &map);
	mlx_hook(map.win_ptr, 3, 0, realease_key, &map);
	mlx_hook(map.win_ptr, 17, 0, red_cross, &map);
	mlx_loop_hook(map.mlx_ptr, move_player, &map);
	mlx_loop(map.mlx_ptr);
}
