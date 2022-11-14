/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:13:51 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 11:44:28 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	init_map2(t_file_data *f_data, char *temp, int *i)
{
	if (f_data->kk > 0 && f_data->empty_string == 1)
		ex_msg("Error. Empty string in map");
	else if (f_data->kk > 0)
	{
		if (temp[0] == ' ' || temp[0] == '1')
		{
			f_data->map_arr[f_data->jj] = ft_strdup(temp);
			f_data->jj += 1;
		}
		else
			ex_msg("Error. Not valid map elements");
		if (f_data->temp_map[*i] == '\0')
			f_data->map_arr[f_data->jj] = NULL;
	}
	else if (f_data->kk == 0)
	{
		f_data->empty_string = 1;
		f_data->map_arr[f_data->jj] = NULL;
	}
}

void	init_map(t_file_data *f_data, int *i)
{
	int		str_count;
	char	*temp;

	if (f_data->temp_map == NULL)
		ex_msg("Error. Empty map file");
	temp = (char *)malloc(10000);
	f_data->jj = 0;
	str_count = ft_count_str(f_data->temp_map) + 1;
	f_data->map_arr = (char **)malloc(sizeof(char *) * str_count);
	while ((f_data->jj)++ < str_count)
		f_data->map_arr[f_data->jj] = NULL;
	f_data->jj = 0;
	while (f_data->temp_map[*i])
	{
		f_data->kk = 0;
		while (f_data->temp_map[*i] != '\n' && f_data->temp_map[*i] != '\0')
			temp[(f_data->kk)++] = f_data->temp_map[(*i)++];
		temp[f_data->kk] = '\0';
		init_map2(f_data, temp, i);
		if (f_data->temp_map[*i])
			(*i)++;
	}
	free(temp);
}
