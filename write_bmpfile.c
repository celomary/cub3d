/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmpfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 00:56:18 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/04 21:56:46 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

static void		set_bmp_header(unsigned char *buff, t_bitmap *bmp, t_map *map)
{
	bmp->pd_offset = 54;
	bmp->header_size = 40;
	bmp->image_width = map->res.x;
	bmp->image_height = map->res.y;
	bmp->bpp = 24;
	bmp->width_in_bytes = ((bmp->image_width * bmp->bpp + 31) / 32) * 4;
	bmp->planes = 1;
	bmp->image_size = bmp->width_in_bytes * bmp->image_height;
	bmp->file_size = 54 + bmp->image_size;
	ft_memcpy(buff, "BM", 2);
	ft_memcpy(buff + 2, &(bmp->file_size), 4);
	ft_memcpy(buff + 10, &(bmp->pd_offset), 4);
	ft_memcpy(buff + 14, &(bmp->header_size), 4);
	ft_memcpy(buff + 18, &(bmp->image_width), 4);
	ft_memcpy(buff + 22, &(bmp->image_height), 4);
	ft_memcpy(buff + 26, &(bmp->planes), 2);
	ft_memcpy(buff + 28, &(bmp->bpp), 2);
	ft_memcpy(buff + 34, &(bmp->image_size), 4);
}

static void		put_color_buff(unsigned char *buffer, t_bitmap *bmp, t_map *map)
{
	int		xy[2];
	int		y2;
	int		color[3];
	int		hex_color;

	xy[1] = map->res.y;
	y2 = 0;
	while (--xy[1] >= 0)
	{
		xy[0] = map->res.x;
		while (--xy[0] >= 0)
		{
			hex_color = get_pixel_img(map, xy[0], xy[1]);
			decimal_to_rgb(hex_color, color, color + 1, color + 2);
			buffer[y2 * bmp->width_in_bytes + xy[0] * 3] = color[2];
			buffer[y2 * bmp->width_in_bytes + xy[0] * 3 + 1] = color[1];
			buffer[y2 * bmp->width_in_bytes + xy[0] * 3 + 2] = color[0];
		}
		y2++;
	}
}

static void		init_header(unsigned char *s)
{
	int		iter;

	iter = 55;
	while (--iter >= 0)
		s[iter] = 0;
}

void			create_bmp(t_map *map)
{
	t_bitmap		bmp;
	int				fd;
	unsigned char	header[54];
	unsigned char	*buffer;

	init_header(header);
	buffer = (unsigned char *)ft_realloc(NULL, 0, bmp.image_size);
	fd = open("img.bmp", O_RDWR | O_CREAT, 500);
	set_bmp_header(header, &bmp, map);
	write(fd, header, 54);
	put_color_buff(buffer, &bmp, map);
	write(fd, buffer, bmp.image_size);
	close(fd);
	free(buffer);
}
