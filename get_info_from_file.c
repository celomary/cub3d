/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:17:30 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 23:09:40 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_resolution(t_map *map, char **str, int *v)
{
	char	**resolution;
	int		len;

	resolution = ft_split(*str, ' ');
	len = table_len(resolution);
	if (len < 3)
	{
		ft_putstr("maybe resolution missing some params :)\n");
		*v = 1;
	}
	else
	{
		map->res.x = ft_atoi(resolution[1]);
		map->res.y = ft_atoi(resolution[2]);
		if ((map->res.x > 2560 || map->res.y > 1440) ||
		(map->res.x < 650 || map->res.y < 350))
		{
			ft_putstr("R must be 650x350 <= R <= 2560x1440\n");
			*v = 1;
		}
	}
	free_chartable(&resolution);
	free(*str);
	*str = NULL;
}

static char		*delete_space_map(char **str)
{
	char	*dspace;
	int		iter;
	int		i;

	iter = 0;
	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] != ' ')
		{
			dspace = (char *)ft_realloc(dspace, iter, iter + 1);
			dspace[iter] = (*str)[i];
			iter++;
		}
		i++;
	}
	free(*str);
	return (dspace);
}

static void		get_map_data(t_map *map, char **str, int fd)
{
	int		iter;
	int		value;

	iter = 1;
	map->str_map = (char **)malloc(sizeof(char *));
	map->str_map[0] = delete_space_map(str);
	while ((value = get_next_line(fd, str)) > 0)
	{
		map->str_map = (char **)ft_realloc(map->str_map,
		iter * sizeof(char *), (iter + 1) * sizeof(char *));
		map->str_map[iter] = delete_space_map(str);
		iter++;
	}
	*str = NULL;
	map->y_table = iter;
	map->x_table = (int)ft_strlen(map->str_map[0]);
}

static int		map_recog(char *line)
{
	if (comp_str(line, "1", 1) || comp_str(line, "0", 1))
		return (1);
	return (0);
}

int				get_info(t_map *map, char *file_name)
{
	int		fd;
	int		value;
	char	*line;
	int		v;

	v = 0;
	fd = open(file_name, O_RDONLY);
	while ((value = get_next_line(fd, &line)) > 0)
	{
		if (comp_str(line, "R", 1))
			get_resolution(map, &line, &v);
		else if (map_recog(line))
			get_map_data(map, &line, fd);
		else if (*line == '\0')
			free(line);
		else if (comp_str(line, "C ", 2))
			set_valid_color(&(map->ciel_color), &line, &v);
		else if (comp_str(line, "F ", 2))
			set_valid_color(&(map->floor_color), &line, &v);
		else
			get_texture_from_file(&line, map);
		if (v)
			break ;
	}
	return (v);
}
