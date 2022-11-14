/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_data_arrays.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:14 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 14:45:27 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	init_check(t_file_data *f_data, char *curr_str)
{
	char	*new_str;
	if (ft_strchr("FC", curr_str[0]) != NULL && f_data->flag_colors != 2)
	{
		new_str = ft_substr(curr_str, 0, ft_strlen(curr_str) - 1);
		init_color(f_data, new_str);
		check_color(f_data, new_str);
		free(new_str);
	}
	else if (ft_strchr("NSWE", curr_str[0]) && f_data->flag_textures != 4)
	{
		new_str = ft_substr(curr_str, 0, ft_strlen(curr_str) - 1);
		init_texture(f_data, new_str);
		check_texture(f_data, new_str);
		free(new_str);
	}
	else if (ft_strchr(" 1", curr_str[0])
		&& f_data->flag_textures == 4 && f_data->flag_colors == 2)
	{	
		f_data->temp_map = ft_strjoin_with_free(f_data->temp_map,
				curr_str, 1, 0);
	}
	else
		ex_msg("Error. Incorrect map file");
}
