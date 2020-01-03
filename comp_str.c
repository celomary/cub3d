/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:38:02 by mel-omar          #+#    #+#             */
/*   Updated: 2019/12/21 21:45:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		comp_str(const char *s1, const char *s2, int n)
{
	int		iter;

	iter = 0;
	while (s2[iter] != '\0' && s1[iter] != '\0' && iter < n)
	{
		if (s1[iter] != s2[iter])
			return (0);
		iter++;
	}
	if (s2[iter] == '\0' && iter < n)
		return (0);
	if (s1[iter] == '\0' && iter < n)
		return (0);
	return (1);
}
