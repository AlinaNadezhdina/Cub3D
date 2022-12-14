/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:55:13 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 12:04:15 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	to_north(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = FOV;
	data->dir_x = -1;
	data->dir_y = 0;
}

void	to_south(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = -FOV;
	data->dir_x = 1;
	data->dir_y = 0;
}

void	to_west(t_data *data)
{
	data->plane_x = -FOV;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = -1;
}

void	to_east(t_data *data)
{
	data->plane_x = FOV;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = 1;
}

int	set_player_position(t_data *data, t_hero_position *hero)
{
	data->p_x = hero->y + 0.5;
	data->p_y = hero->x + 0.5;
	data->map->lines[hero->y][hero->x] = '0';
	if (hero->direction == 'N')
		to_north(data);
	else if (hero->direction == 'E')
		to_east(data);
	else if (hero->direction == 'W')
		to_west(data);
	else if (hero->direction == 'S')
		to_south(data);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
