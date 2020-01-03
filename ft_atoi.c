/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 23:26:41 by mel-omar          #+#    #+#             */
/*   Updated: 2019/12/03 23:43:26 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(char *str)
{
	long int	result;
	int			sign;

	sign = 1;
	while (*str != '\0' &&
			(*str < '0' || *str > '9') && *str != '+' && *str != '-')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
