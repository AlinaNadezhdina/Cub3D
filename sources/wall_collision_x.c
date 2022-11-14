/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:20:33 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:13:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_in_front_x(t_data *data, double len)
{
	int			x;
	int			y;

	if (data->dir_x > 0)
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_behind_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((data->p_x - (data->dir_x) / len * SPEED) + WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_left_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_x - WALL_DISTANCE);
	else
		y = (int)(data->p_x + WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}

int	wall_right_x(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)(data->p_x + WALL_DISTANCE);
	else
		y = (int)(data->p_x - WALL_DISTANCE);
	x = (int)(data->p_y - (data->dir_y) / len * SPEED);
	if (data->map->lines[y][x] == '0')
		return (false);
	return (true);
}
