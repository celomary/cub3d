/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:40 by mel-omar          #+#    #+#             */
/*   Updated: 2020/01/03 23:55:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_player
{
	float		x;
	float		y;
	float		theta;
	float		cos_p;
	float		sin_p;
}				t_player;

typedef struct	s_tuple
{
	char		a;
	float		b;
	float		x;
	float		y;
	float		o;
}				t_tuple;

typedef struct	s_sprite_params
{
	float		dist;
	float		x;
	float		o;
}				t_sprite_params;

typedef struct	s_texture
{
	int			*data;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_map
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	char		**str_map;
	t_player	player;
	t_vector	res;
	t_vector	grid;
	int			y_inter;
	int			x_inter;
	int			x_table;
	int			y_table;
	int			ciel_color;
	int			floor_color;
	t_texture	texture[5];
	int			updown;
	int			keys[4];
}				t_map;

float			to_radian(float deg);
float			to_degree(float radian);
int				get_offset(t_map *map, char c, int x, int y);
char			**ft_split(char *str, char c);
void			free_chartable(char ***table);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				rgb_to_decimal(int r, int g, int b);
void			decimal_to_rgb(int decimal, int *r, int *g, int *b);
int				shading_color(int color, float distance);
float			new_x(t_map *map, t_vector old);
float			new_y(t_map *map, t_vector old);
t_vector		point_axis(t_map *map, t_vector point, float o);
float			actual_height(t_map *map, float distance, float o);
float			start_y(t_map *map, float height);
void			get_texture_data(t_map *map, t_texture *texture, char *fname);
void			get_texture_from_file(char **str, t_map *map);
int				get_pixel_from_img(t_map *map,
		t_tuple *tup, float height, int y);
int				get_sprite_color(t_map *map, float offset, float height, int y);
float			get_distance(t_vector a, t_vector b);
float			modulo(float o);
void			ft_putstr(char *str);
int				pressed_key(int key, void *param);
int				realease_key(int key, void *param);
int				comp_str(const char *s1, const char *s2, int n);
int				sin_sign(float theta);
int				cos_sign(float theta);
int				is_filecub(char *file);
int				notvalidfile(char *fname);
void			put_pixel_img(t_map *map, int x, int y, int color);
void			refresh_window(t_map *map, void func(t_map *map));
void			image(t_map *map);
int				get_info(t_map *map, char *fname);
t_vector		*get_horizental_point(t_map *map, float x, float y, float o);
t_vector		*get_vertical_point(t_map *map, float x, float y, float o);
t_tuple			*get_small_distance(t_vector *point, t_vector *a, t_vector *b);
void			draw_sprite(t_map *map, t_tuple *dis_b, int x, float o);
void			draw_sprites(t_map *map, t_vector *horizental,
		t_vector *vertical, t_sprite_params params);
void			draw_map2d(t_map *map);
void			draw_player2d(t_map *map);
void			view3d(t_map *map);
int				get_player_pos(t_map *map);
int				check_texture_files(char *file);
int				check_duplicate(char *fname);
int				init_map(t_map *map, char *fname);
int				move_player(t_map *map);
t_vector		player_axis(t_player player);
int				table_len(char **table);
void			set_valid_color(int *color, char **line, int *v);
void			play(char *fname);
int				check_map(t_map *map);
int				start(char *str);
t_vector		init_vector(float x, float y);
void			free_gnl(int fd);
int				check_missing_params(int **dep);
void			clear(t_map *map);
int				red_cross(void *param);
#endif
