/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:20:26 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/02 15:16:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_buffer(char **buffer)
{
	if (*buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

static int		checker(char **line, char **buffer, int *pos)
{
	if (*pos == 0 && *buffer)
	{
		free_buffer(buffer);
		*pos = -2;
		if (**line == '\0')
		{
			*line = 0;
			return (0);
		}
	}
	else if (*pos == -2)
	{
		*line = 0;
		return (0);
	}
	return (1);
}

static int		get_next_line_helper(int fd, char **line,
		char **buffer, int *pos)
{
	static size_t	current;
	size_t			len;
	size_t			old_size;

	old_size = 0;
	if (update_data(fd, buffer, &current, pos) == -1)
		return (-1);
	while (*buffer)
	{
		if (update_data(fd, buffer, &current, pos) == -1)
			return (-1);
		len = get_length(*buffer, current, *pos);
		if (!(*line = (char *)ft_realloc(*line, old_size, old_size + len)))
			return (-1);
		copy_to_line(line, *buffer + current, old_size, len);
		current += len + 1;
		if ((*buffer)[current - 1] == '\n')
		{
			break ;
		}
		old_size += len;
	}
	return (checker(line, buffer, pos));
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer;
	static int		pos;

	*line = NULL;
	if (pos <= 0)
	{
		pos = 0;
		if (!(buffer = malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	}
	return (get_next_line_helper(fd, line, &buffer, &pos));
}
