/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:29:27 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 12:08:28 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "validation.h"

# define EXIT_FAILURE 	1
# define EXIT_SUCCESS 	0
# define WIDTH			1024
# define HEIGHT			512
# define SPEED			0.03
# define ROTATE_SPEED	-0.03 // in radians
# define FOV			0.66
# define SIZE_XPM 		64
# define WALL_DISTANCE 	0.3
# define CORNER			0.25

// keycodes
# define MOVE_LEFT 		0
# define MOVE_RIGHT 	2
# define MOVE_DOWN 		1
# define MOVE_UP 		13
# define ROTATE_LEFT 	123
# define ROTATE_RIGHT 	124
# define ESCAPE 		53

typedef enum s_cnt
{
	move_up = 13,
	move_down = 1,
	move_left = 0,
	move_right = 2,
	rotate_left = 123,
	rotate_right = 124,
	escape = 53,
}	t_cnt;

typedef enum e_tex
{
	north = 0,
	east = 1,
	west = 2,
	south = 3
}	t_tex;

typedef struct s_ray
{
	float	camera;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_textures
{
	int		east_wall[SIZE_XPM][SIZE_XPM];
	int		west_wall[SIZE_XPM][SIZE_XPM];
	int		north_wall[SIZE_XPM][SIZE_XPM];
	int		south_wall[SIZE_XPM][SIZE_XPM];
	void	*tex_ptr[4];
	char	*tex_addr;
}	t_textures;

typedef struct s_controls
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
	int	escape;
}	t_controls;

typedef struct s_wall
{
	int		top;
	int		bottom;
	int		x;
	double	step;
	double	position;
	int		direction;
	char	type;
	int		vertical;
	int		horizontal;
}	t_wall;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			floor[3];
	int			ceiling[3];
	char		*tex_path[4];
	t_textures	textures;
}	t_img;

typedef struct s_data
{
	float		p_x;
	float		p_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	float		delta_x;
	float		delta_y;
	void		*mlx_ptr;
	void		*mlx_win;
	t_controls	controls;
	t_map		*map;
	t_img		img;
	t_ray		ray;
	t_wall		wall;
	t_cnt		cnt;
}	t_data;

//=======================set_position.c=================//
int		set_player_position(t_data *data, t_hero_position *hero);

//========================events.c=======================//
int		exit_game(t_data *data, int exit_state);
int		mouse_hook(int x, int y, t_data *data);
int		key_release(int key, t_data *data);
int		key_press(int keycode, t_data *data);
void	check_events(t_data *data);

//========================events_moving.c================//
void	redrawing(t_data *data, int keycode);

//=========================free.c========================//
void	free_texture_paths(t_img *img);
void	free_all(t_data *data);

//=======================textures.c======================//
int		get_textures(t_data *data, t_validate *val);

//========================mlx_funcs.c=====================//
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		my_mlx_pixel_get(t_img *img, int x, int y);
int		create_rgb(int r, int g, int b);
int		get_color(char c);

//========================draw_game.c======================//
int		draw_game(t_data *data);

//========================rays.c===========================//
void	set_direction(t_data *data, t_ray *ray);
bool	is_wall(t_data *data, int x, int y, int p_x);
void	searching_wall(t_data *data, t_ray *ray, int p_x);
double	get_perp_wall_dist(t_data *data);
int		get_ray(t_data *data, int x);

//========================wall.c===========================//
void	draw_walls(t_data *data, int x);

//========================wall_collision_x.c=================//
int		wall_in_front_x(t_data *data, double len);
int		wall_behind_x(t_data *data, double len);
int		wall_left_x(t_data *data, double len);
int		wall_right_x(t_data *data, double len);

//========================wall_collision_y.c=================//
int		wall_in_front_y(t_data *data, double len);
int		wall_behind_y(t_data *data, double len);
int		wall_left_y(t_data *data, double len);
int		wall_right_y(t_data *data, double len);

//=========================minimap.c=========================//
int		draw_minimap(t_data *data);

#endif