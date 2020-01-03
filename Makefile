# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 21:10:41 by mel-omar          #+#    #+#              #
#    Updated: 2020/01/03 18:42:53 by mel-omar         ###   ########.fr        #
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
	  error_handling.c errors.c display.c get_info_from_file2.c\
	  check_map.c main.c

OBJ = ft_atoi.o ft_split.o get_next_line.o get_next_line_utils.o\
	  get_info_from_file.o image_handling.o horizental_intercept.o\
	  ft_strlen.o additional_function.o init_map.o player_info.o\
	  move_player.o vertical_intercept.o draw_map2d.c draw_player2d.o\
	  some_math_funcn.o projection.o new_axis.o view3d.c play.o\
	  texture.o cos_sine_sign.o comp_str.o free_chartable.o\
	  sprite.o draw_sprites.o key_handler.o colors.o image.o\
	  error_handling.o errors.o display.o get_info_from_file2.o\
	  check_map.o main.o

all :
	gcc	-Wall -Wextra -Werror $(SRC) libmlx.a -framework Opengl -framework AppKit -lm -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)