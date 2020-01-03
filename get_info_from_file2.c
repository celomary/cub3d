/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:10:06 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 23:23:40 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		color_in_valid_format(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	return (0);
}

static int		is_valid_rgb(int color, int *v)
{
	if (color > 255)
	{
		ft_putstr("check rgb range!\n");
		*v = 1;
	}
	return (color);
}

static void		init_colors(int *r, int *g, int *b)
{
	*r = 0;
	*g = 0;
	*b = 0;
}

void			set_valid_color(int *color, char **line, int *v)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	init_colors(&r, &g, &b);
	colors = ft_split(*line + start(*line), ',');
	*v = 0;
	free(*line);
	if (color_in_valid_format(colors[0]))
		r = is_valid_rgb(ft_atoi(colors[0]), v);
	else
		*v = 1;
	if (color_in_valid_format(colors[1]))
		g = is_valid_rgb(ft_atoi(colors[1]), v);
	else
		*v = 1;
	if (color_in_valid_format(colors[2]))
		b = is_valid_rgb(ft_atoi(colors[2]), v);
	else
		*v = 1;
	*color = rgb_to_decimal(r, g, b);
	free_chartable(&colors);
	if (*v)
		ft_putstr("rgb color invalid format :(\n");
}

int				table_len(char **table)
{
	int		len;

	len = 0;
	while (*table)
	{
		len++;
		table++;
	}
	return (len);
}
