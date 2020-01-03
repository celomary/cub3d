/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:51:45 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/01 21:03:58 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64

# include <stdlib.h>
# include <unistd.h>

void	*ft_realloc(void *old_buffer, unsigned int old_size,
		unsigned int new_size);
size_t	get_length(char *buffer, size_t	current, int pos);
int		update_data(int	fd, char **buffer, size_t *current, int *pos);
void	copy_to_line(char **line, char *buffer, size_t old_size, size_t len);
int		get_next_line(int fd, char **line);
#endif
