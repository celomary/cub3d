/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 22:41:51 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 23:03:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_missing_params(int **dep)
{
	int		iter;

	iter = -1;
	while (++iter < 8)
	{
		if ((*dep)[iter] == 0)
		{
			free(*dep);
			ft_putstr("maybe there is missing parameter :(\n");
			return (1);
		}
	}
	free(*dep);
	return (0);
}
