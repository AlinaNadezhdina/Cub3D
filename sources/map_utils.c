/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:49 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:07:24 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	search_max_string(t_file_data *f_data)
{
	int		i;
	size_t	len;
	size_t	tmp;

	i = -1;
	len = ft_strlen(f_data->map_arr[0]);
	while (++i < f_data->map_height - 1)
	{
		tmp = ft_strlen(f_data->map_arr[i]);
		if (len < tmp)
			len = tmp;
	}
	return ((int)len);
}
