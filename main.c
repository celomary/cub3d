/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:40:57 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/04 22:02:25 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("file.cub is missing!\n");
		return (1);
	}
	if (!is_filecub(argv[1]))
	{
		ft_putstr("file does not have extension .cub!\n");
		return (1);
	}
	if (notvalidfile(argv[1]))
	{
		ft_putstr("oooops! can't open ");
		ft_putstr(argv[1]);
		ft_putstr("\n");
		return (1);
	}
	if (check_duplicate(argv[1]) || check_texture_files(argv[1]))
		return (1);
	if (argc >= 3)
		play(argv[1], argv[2]);
	else
		play(argv[1], NULL);
	return (0);
}
