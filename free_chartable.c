/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chartable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:30:54 by mel-omar          #+#    #+#             */
/*   Updated: 2019/12/21 21:39:30 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_chartable(char ***table)
{
	int		iter;
	char	**before;

	before = *table;
	iter = 0;
	while (before[iter])
	{
		free(before[iter]);
		iter++;
	}
	free(*table);
}
