/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:07:03 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/04 21:02:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_decimal(int r, int g, int b)
{
	return (pow(256, 2) * r + 256 * g + b);
}

void	decimal_to_rgb(int decimal, int *r, int *g, int *b)
{
	*r = decimal / pow(256, 2);
	*g = (decimal / 256) % 256;
	*b = decimal % 256;
}

int		shading_color(int color, float distance)
{
	int		r;
	int		g;
	int		b;

	if (distance < 1)
		return (color);
	decimal_to_rgb(color, &r, &g, &b);
	return (rgb_to_decimal(r / distance, g / distance, b / distance));
}
