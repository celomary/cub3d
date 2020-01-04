/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:48:37 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/04 17:43:54 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, void *src, size_t bytes)
{
	size_t			iter;

	iter = 0;
	while (iter < bytes && ((unsigned char *)src)[iter] != '\0')
	{
		((unsigned char *)dst)[iter] = ((unsigned char *)src)[iter];
		iter++;
	}
	return (dst);
}
