/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:24:26 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:07:04 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_in_front_y(t_data *data, double len)
{
	int			x;
	int			y;

	if (data->dir_y > 0)
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_y + (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_behind_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_y > 0)
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) - WALL_DISTANCE);
	else
		y = (int)((data->p_y - (data->dir_y) / len * SPEED) + WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_left_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_y + WALL_DISTANCE);
	else
		y = (int)(data->p_y - WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}

int	wall_right_y(t_data *data, double len)
{
	int		x;
	int		y;

	if (data->dir_x > 0)
		y = (int)(data->p_y - WALL_DISTANCE);
	else
		y = (int)(data->p_y + WALL_DISTANCE);
	x = (int)(data->p_x + (data->dir_x) / len * SPEED);
	if (data->map->lines[x][y] == '0')
		return (false);
	return (true);
}
