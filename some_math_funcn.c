/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_math_funcn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:02:15 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 18:17:33 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		get_distance(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

float		modulo(float o)
{
	if (o > 360)
		return (o - 360);
	if (o < 0)
		return (360 + o);
	return (o);
}

t_tuple		*init_tuple(char a, float dis, float x, float y)
{
	t_tuple		*tup;

	tup = malloc(sizeof(t_tuple));
	tup->a = a;
	tup->b = dis;
	tup->x = x;
	tup->y = y;
	return (tup);
}

t_tuple		*get_small_distance(t_vector *point, t_vector *a, t_vector *b)
{
	t_tuple		*tuple;
	float		dis_a;
	float		dis_b;

	dis_a = get_distance(*point, *a);
	dis_b = get_distance(*point, *b);
	if (dis_b <= dis_a)
		tuple = init_tuple('v', dis_b, b->x, b->y);
	else
		tuple = init_tuple('h', dis_a, a->x, a->y);
	return (tuple);
}
