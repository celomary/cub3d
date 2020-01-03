/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:31:52 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 00:15:33 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			valid_element(char c)
{
	if (c == '1' || c == '2' || c == '0'
			|| c == 'N' || c == 'S' || c == 'E'
			|| c == 'W')
	{
		return (1);
	}
	return (0);
}

static int			check_first_last(char *line, int *len)
{
	*len = -1;
	while (line[++(*len)] != '\0')
	{
		if (line[*len] != '1')
			return (1);
	}
	return (0);
}

static int			check_middle(char *line, int *len)
{
	*len = 0;
	if (line[0] != '1')
		return (1);
	while (line[++(*len) + 1] != '\0')
	{
		if (!valid_element(line[(*len)]))
			return (1);
	}
	if (line[(*len)] != '1')
		return (1);
	*len += 1;
	return (0);
}

int					check_map(t_map *map)
{
	int		y;
	int		len;
	int		value;

	value = 0;
	if (check_first_last(map->str_map[0], &value))
		return (1);
	y = 0;
	while (++y + 1 < map->y_table)
	{
		if (check_middle(map->str_map[y], &len))
			return (1);
		if (value != len)
			return (1);
	}
	if (check_first_last(map->str_map[y], &len))
		return (1);
	if (value != len)
		return (1);
	return (0);
}
