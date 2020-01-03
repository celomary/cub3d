/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:51:06 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/01 21:25:17 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *buffer, unsigned int old_size, unsigned int new_size)
{
	unsigned char	*new_buffer;
	unsigned int	iter;
	unsigned char	*old_buffer;

	old_buffer = (unsigned char *)buffer;
	iter = 0;
	new_buffer = (unsigned char *)malloc(new_size * sizeof(unsigned char *));
	while (iter < old_size)
	{
		new_buffer[iter] = old_buffer[iter];
		iter++;
	}
	while (iter <= new_size)
	{
		new_buffer[iter] = 0;
		iter++;
	}
	if (old_size > 0)
		free(buffer);
	return (new_buffer);
}

size_t	get_length(char *buffer, size_t current, int pos)
{
	size_t	len;
	size_t	position;

	position = (size_t)pos;
	len = 0;
	while (buffer[current + len] != '\n' && current + len < position)
		len++;
	return (len);
}

int		update_data(int fd, char **buffer, size_t *current, int *pos)
{
	if (*pos == 0 || *current >= (size_t)*pos)
	{
		*pos = read(fd, *buffer, BUFF_SIZE);
		*current = 0;
		if (*pos == 0)
			(*buffer)[0] = '\n';
	}
	return (*pos);
}

void	copy_to_line(char **line, char *buffer, size_t old_size, size_t len)
{
	size_t	iter;

	iter = 0;
	while (iter < len)
	{
		(*line)[iter + old_size] = buffer[iter];
		iter++;
	}
}
