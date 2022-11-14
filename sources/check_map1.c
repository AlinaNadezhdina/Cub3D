/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:35:20 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:10:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	ft_fill_map_width(t_file_data *f_data, int i)
{
	char	*ptr;

	i = -1;
	ptr = (char *)malloc((f_data->map_width + 1) * sizeof(char));
	while (++i < f_data->map_width)
		ptr[i] = ' ';
	ptr[i] = '\0';
	ft_memcpy(ptr, f_data->map_arr[f_data->ii],
		ft_strlen(f_data->map_arr[f_data->ii]));
	free (f_data->map_arr[f_data->ii]);
	f_data->map_arr[f_data->ii] = ptr;
}

void	map_normalize(t_file_data *f_data)
{
	f_data->ii = -1;
	while (++(f_data->ii) < f_data->map_height)
	{
		if ((int)ft_strlen(f_data->map_arr[f_data->ii]) < f_data->map_width)
			ft_fill_map_width(f_data, f_data->ii);
	}
}

int	check_map_quadro(t_file_data *f_data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(f_data->map_arr[0]);
	while (i < f_data->map_height && ft_strlen(f_data->map_arr[i]) == len)
	{
		i++;
	}
	if (f_data->map_arr[++i] == NULL)
		return (0);
	return (1);
}

void	check_map(t_file_data *f_data)
{
	f_data->map_height = ft_count_str_array(f_data);
	f_data->map_width = search_max_string(f_data);
	if (check_map_quadro(f_data))
		map_normalize(f_data);
	check_border(f_data);
	check_map_in(f_data);
}
