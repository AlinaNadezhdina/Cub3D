/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:18:56 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 11:18:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define BORDER_CHAR "1 "
# define IN_CHAR "NSEW0"
# define MAP_CHAR "NSEW 01"
# define HERO_CHAR "NSEW"

typedef struct s_file_data
{
	char	**texture_arr;
	char	**color_arr;
	char	**map_arr;
	int		map_fd;
	int		map_width;
	int		map_height;
	char	*temp_map;
	int		flag_colors;
	int		flag_textures;
	int		flag_in;
	int		flag_hero;
	int		hpx;
	int		hpy;
	char	arch[9];
	char	direction;
	int		f[3];
	int		c[3];
	int		ii;
	int		jj;
	int		kk;
	int		str_len;
	char	cc;
	int		empty_string;
}t_file_data;

typedef struct s_vWall
{
	char	*we;
	char	*ea;
	char	*no;
	char	*so;
}	t_vWall;

typedef struct s_colors
{
	int	floor[3];
	int	ceiling[3];
}	t_colors;

typedef struct s_map
{
	char	**lines;
	int		width;
	int		heigth;
	char	*char_list;
}	t_map;

typedef struct s_hero_position
{
	int		x;
	int		y;
	char	direction;
}	t_hero_position;

typedef struct s_validate
{
	t_map			map;
	t_colors		colors;
	t_hero_position	hero;
	t_vWall			wall;
}	t_validate;

//==============validate_file.c===================//
t_validate	*validate_file(char *s, int c);

//===============map_utils.c======================//
int			search_max_string(t_file_data *f_data);

//===============utilites.c=======================//
void		ft_str_trim(char **str);
char		*ft_strjoin_with_free(char *str1, char *str2,
				int free_1, int free_2);
int			ft_count_str(char *str);
int			ft_count_str_array(t_file_data *f_data);
void		ex_msg(char *msg);

//=============init_file_data_arrays.c============//
void		init_check(t_file_data *f_data, char *curr_str);

//=============init_color.c====================//
void		init_color(t_file_data *f_data, char *str);
void		check_color(t_file_data *f_data, char *curr_str);

//=============init_texture.c====================//
void		init_texture(t_file_data *f_data, char *str);
void		check_texture(t_file_data *f_data, char *curr_str);

//===============init_map.c====================//
void		init_map(t_file_data *f_data, int *i);

//===============check_map1.c===================//
void		check_map(t_file_data *f_data);

//===============check_map2.c===================//
void		check_border(t_file_data *f_data);
void		check_map_in(t_file_data *f_data);
void		ft_flag_set(t_file_data *f_data);
#endif