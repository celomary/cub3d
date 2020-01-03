# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 21:10:41 by mel-omar          #+#    #+#              #
#    Updated: 2020/01/02 20:12:23 by mel-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = ft_atoi.c ft_split.c get_next_line.c get_next_line_utils.c\
	  get_info_from_file.c image_handling.c horizental_intercept.c\
	  ft_strlen.c additional_function.c init_map.c player_info.c\
	  move_player.c vertical_intercept.c draw_map2d.c draw_player2d.c\
	  some_math_funcn.c projection.c new_axis.c view3d.c play.c\
	  texture.c cos_sine_sign.c comp_str.c free_chartable.c\
	  sprite.c draw_sprites.c key_handler.c colors.c image.c\
	  error_handling.c error_handling2.c display.c get_info_from_file2.c\
	  check_map.c

OBJ = ft_atoi.o ft_split.o get_next_line.o get_next_line_utils.o\
	  get_info_from_file.o image_handling.o horizental_intercept.o

all :
	gcc	$(SRC) main.c libmlx.a -framework Opengl -framework AppKit -lm -o f