/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:58:29 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:21:11 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_texture_data(t_map *map, t_texture *texture, char *fname)
{
	void	*img;
	int		k;

	img = mlx_xpm_file_to_image(map->mlx_ptr,
	fname, &(texture->width), &(texture->height));
	texture->data = (int *)mlx_get_data_addr(img, &k, &k, &k);
}

int			get_texture_index(t_tuple *tup)
{
	if (tup->o > 640)
		return (4);
	if (tup->a == 'h' && sin_sign(tup->o) == 1)
		return (1);
	else if (tup->a == 'h' && sin_sign(tup->o) == -1)
		return (0);
	else if (tup->a == 'v' && cos_sign(tup->o) == 1)
		return (3);
	return (2);
}

void		get_texture_from_file(char **str, t_map *map)
{
	char	**table;

	table = ft_split(*str, ' ');
	if (comp_str(table[0], "NO", 2))
		get_texture_data(map, map->texture, table[1]);
	else if (comp_str(table[0], "SO", 2))
		get_texture_data(map, map->texture + 1, table[1]);
	else if (comp_str(table[0], "WE", 2))
		get_texture_data(map, map->texture + 2, table[1]);
	else if (comp_str(table[0], "EA", 2))
		get_texture_data(map, map->texture + 3, table[1]);
	else if (comp_str(table[0], "S", 1))
		get_texture_data(map, map->texture + 4, table[1]);
	free_chartable(&table);
	free(*str);
}

int			get_pixel_from_img(t_map *map, t_tuple *tup, float height, int y)
{
	int		index;
	int		offset;
	float	x_ratio;
	float	y_ratio;

	index = get_texture_index(tup);
	x_ratio = map->texture[index].width / map->grid.x;
	y_ratio = map->texture[index].height / height;
	offset = get_offset(map, tup->a, tup->x, tup->y) * x_ratio;
	return (map->texture[index].data[(int)(offset +
	(int)(y * y_ratio) * map->texture[index].width)]);
}

int			get_sprite_color(t_map *map, float offset, float height, int y)
{
	float	y_ratio;
	float	x_ratio;
	int		color;

	y_ratio = map->texture[4].height / height;
	x_ratio = map->texture[4].width / map->grid.x;
	color = map->texture[4].data[(int)((offset * x_ratio) +
	(int)(y * y_ratio) * map->texture[4].width)];
	return (color);
}
