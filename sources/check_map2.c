/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:39:28 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:14:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	check_border(t_file_data *f_data)
{
	f_data->ii = -1;
	f_data->jj = f_data->map_height - 1;
	while (++(f_data->ii) < f_data->map_width)
	{
		if (!(ft_strchr(BORDER_CHAR, f_data->map_arr[0][f_data->ii])))
			ex_msg("Error. Invalid map border line1");
		if (!(ft_strchr(BORDER_CHAR, f_data->map_arr[f_data->jj][f_data->ii])))
			ex_msg("Error. Invalid map border line2");
	}
	f_data->ii = -1;
	f_data->jj = f_data->map_width - 1;
	while (++(f_data->ii) < f_data->map_height)
	{
		if (!(ft_strchr(BORDER_CHAR, f_data->map_arr[f_data->ii][0])) ||
		!(ft_strchr(BORDER_CHAR, f_data->map_arr[f_data->ii][f_data->jj])))
			ex_msg("Error. Invalid map border column");
	}
}

void	ft_flag_set(t_file_data *f_data)
{
	if (f_data->jj == 1 && f_data->map_arr[f_data->ii][f_data->jj - 1] == '1')
		f_data->flag_in = (f_data->flag_in + 1) % 2;
	if (f_data->cc == '1' && f_data->map_arr[f_data->ii][f_data->jj - 1] == ' ')
		f_data->flag_in = (f_data->flag_in + 1) % 2;
	if (f_data->cc == '1' && f_data->map_arr[f_data->ii][f_data->jj + 1] == ' ')
		f_data->flag_in = (f_data->flag_in + 1) % 2;
	if (ft_strchr(HERO_CHAR, f_data->cc))
	{
		if (f_data->flag_in == 0 || f_data->flag_hero == 1)
		{
			ex_msg("Error. Invalid heroe");
		}
		else
		{
			f_data->flag_hero = 1;
			f_data->hpx = f_data->jj;
			f_data->hpy = f_data->ii;
			f_data->direction = f_data->cc;
		}
	}
}

int	ft_leacks_corner(t_file_data *f_data)
{
	char	arch[9];

	if (!ft_strchr(IN_CHAR, f_data->cc))
		return (0);
	arch[0] = f_data->map_arr[f_data->ii - 1][f_data->jj - 1];
	arch[1] = f_data->map_arr[f_data->ii - 1][f_data->jj];
	arch[2] = f_data->map_arr[f_data->ii - 1][f_data->jj + 1];
	arch[3] = f_data->map_arr[f_data->ii][f_data->jj + 1];
	arch[4] = f_data->map_arr[f_data->ii + 1][f_data->jj + 1];
	arch[5] = f_data->map_arr[f_data->ii + 1][f_data->jj];
	arch[6] = f_data->map_arr[f_data->ii + 1][f_data->jj - 1];
	arch[7] = f_data->map_arr[f_data->ii][f_data->jj - 1];
	arch[8] = '\0';
	if (ft_strchr(arch, ' '))
		return (1);
	return (0);
}

void	check_map_in(t_file_data *f_data)
{
	f_data->ii = 0;
	while (++(f_data->ii) < f_data->map_height - 1)
	{
		f_data->jj = 0;
		f_data->flag_in = 0;
		while (++(f_data->jj) < f_data->map_width - 1)
		{
			f_data->cc = f_data->map_arr[f_data->ii][f_data->jj];
			ft_flag_set(f_data);
			if (!ft_strchr(MAP_CHAR, f_data->cc))
				ex_msg("Error. Invalid map char");
			if (ft_leacks_corner(f_data))
			{
				ft_putendl_fd(f_data->map_arr[f_data->ii], 1);
				ex_msg("Error. Whitespaces inside the map");
			}
		}
	}
	if (f_data->flag_hero == 0)
		ex_msg("Error. Hero is absent");
}
