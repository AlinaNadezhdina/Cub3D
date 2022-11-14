/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:21:19 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 11:17:32 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	validate_free(t_file_data *f_d)
{
	free(f_d->color_arr[0]);
	free(f_d->color_arr[1]);
	free(f_d->color_arr);
	free(f_d->texture_arr[0]);
	free(f_d->texture_arr[1]);
	free(f_d->texture_arr[2]);
	free(f_d->texture_arr[3]);
	free(f_d->texture_arr);
	f_d->ii = -1;
	while (++(f_d->ii) < f_d->map_height)
		free(f_d->map_arr[f_d->ii]);
	free(f_d->map_arr[f_d->ii]);
	free(f_d->map_arr[f_d->ii]);
	free(f_d->map_arr);
	free(f_d->temp_map);
}

t_validate	*validate_init(t_file_data *f_d)
{
	t_validate	*val;

	val = malloc(sizeof(t_validate));
	f_d->ii = -1;
	while (++(f_d->ii) < 3)
	{
		val->colors.floor[f_d->ii] = f_d->f[f_d->ii];
		val->colors.ceiling[f_d->ii] = f_d->c[f_d->ii];
	}
	val->wall.no = ft_strdup(f_d->texture_arr[0]);
	val->wall.so = ft_strdup(f_d->texture_arr[1]);
	val->wall.we = ft_strdup(f_d->texture_arr[2]);
	val->wall.ea = ft_strdup(f_d->texture_arr[3]);
	val->map.width = f_d->map_height;
	val->map.heigth = f_d->map_width;
	val->map.lines = malloc(sizeof(char *) * (f_d->map_height + 1));
	f_d->ii = -1;
	while (++(f_d->ii) < f_d->map_height)
		val->map.lines[f_d->ii] = ft_strdup(f_d->map_arr[f_d->ii]);
	val->map.char_list = ft_strdup(MAP_CHAR);
	val->hero.direction = f_d->direction;
	val->hero.x = f_d->hpx;
	val->hero.y = f_d->hpy;
	validate_free(f_d);
	return (val);
}

void	initial_arrays(t_file_data *data)
{
	int	i;

	i = -1;
	data->color_arr = (char **)malloc(sizeof(char *) * 2);
	data->texture_arr = (char **)malloc(sizeof(char *) * 4);
	if (data->color_arr == NULL || data->texture_arr == NULL)
		ex_msg("Error. Init array malloc's error");
	data->color_arr[0] = NULL;
	data->color_arr[1] = NULL;
	while (++i < 4)
		data->texture_arr[i] = NULL;
	data->flag_colors = 0;
	data->flag_textures = 0;
	data->flag_hero = 0;
	data->empty_string = 0;
}

t_file_data	read_file(int map_fd)
{
	t_file_data	f_data;
	char		*current_str;
	int			i;

	i = 0;
	initial_arrays(&f_data);
	current_str = get_next_line(map_fd);
	while (current_str)
	{	
		if (current_str[0] != '\n')
			init_check(&f_data, current_str);
		free(current_str);
		current_str = get_next_line(map_fd);
	}
	init_map(&f_data, &i);
	check_map(&f_data);
	return (f_data);
}

t_validate	*validate_file(char *s, int c)
{
	int			len;
	int			map_fd;
	t_file_data	file_data;

	if (c != 2)
		ex_msg("Error. wrong number of arguments");
	len = ft_strlen(s);
	if (len == 0 || s[len - 1] != 'b' || \
		s[len - 2] != 'u' || s[len - 3] != 'c' || s[len - 4] != '.')
		ex_msg("Error. Wrong map extension\n");
	map_fd = open(s, O_RDONLY);
	if (map_fd == -1)
		ex_msg("Error. Cannot open map\n");
	file_data = read_file(map_fd);
	return (validate_init(&file_data));
}
