/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 00:18:30 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:54:56 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				start(char *str)
{
	int		s;

	s = 2;
	while (str[s] == ' ' && str[s] != '\0')
		s++;
	return (s);
}

int				check_texture_files(char *file)
{
	char	*line;
	int		fd;
	int		value;

	fd = open(file, O_RDONLY);
	while ((value = get_next_line(fd, &line)) > 0)
	{
		if (comp_str(line, "NO", 2) || comp_str(line, "SO", 2)
		|| comp_str(line, "WE", 2) || comp_str(line, "EA", 2)
		|| comp_str(line, "S ", 2))
		{
			if (notvalidfile(line + start(line)))
			{
				ft_putstr("please check textures sprite ... path :(\n");
				free(line);
				free_gnl(fd);
				close(fd);
				return (1);
			}
			free(line);
		}
	}
	close(fd);
	return (0);
}

static int		is_duplicate(int *dep)
{
	int		index;

	index = -1;
	while (++index < 8)
	{
		if (dep[index] > 1)
			return (1);
	}
	return (0);
}

static int		check_duplicate_helper(char *line, int *dep)
{
	if (comp_str("R ", line, 2))
		dep[0]++;
	else if (comp_str("NO", line, 2))
		dep[1]++;
	else if (comp_str("SO", line, 2))
		dep[2]++;
	else if (comp_str("WE", line, 2))
		dep[3]++;
	else if (comp_str("EA", line, 2))
		dep[4]++;
	else if (comp_str("S ", line, 2))
		dep[5]++;
	else if (comp_str("F ", line, 2))
		dep[6]++;
	else if (comp_str("C ", line, 2))
		dep[7]++;
	else if (line[0] != '\0' && line[0] != '1' && line[1] != '0')
	{
		ft_putstr("there is undefined identifier in a file:)\n");
		return (2);
	}
	if (is_duplicate(dep))
		return (1);
	return (0);
}

int				check_duplicate(char *file)
{
	int		*dep;
	int		fd;
	char	*line;
	int		val;

	dep = (int *)ft_realloc(NULL, 0, sizeof(int) * 8);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if ((val = check_duplicate_helper(line, dep)))
		{
			if (val == 1)
				ft_putstr("there are duplicate things in your file!\n");
			free(line);
			free(dep);
			free_gnl(fd);
			close(fd);
			return (1);
		}
		free(line);
	}
	free(dep);
	close(fd);
	return (0);
}
