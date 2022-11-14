/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:53:41 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:06:10 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	check_t_fornull(t_file_data *f_data)
{
	f_data->ii = -1;
	while (++(f_data->ii) < 4)
	{
		if (f_data->texture_arr[f_data->ii] == NULL)
			return (1);
	}
	return (0);
}

void	check_texture(t_file_data *f_data, char *curr_str)
{
	char	*temp;

	temp = ft_strdup(&curr_str[2]);
	ft_str_trim(&temp);
	f_data->kk = open(temp, O_RDONLY);
	if (f_data->kk < 0)
		ex_msg("Error. Incorrect texture path");
	close(f_data->kk);
	free(temp);
}

void	init_texture(t_file_data *f_data, char *curr_str)
{
	char	*temp;

	temp = ft_strdup(&curr_str[2]);
	ft_str_trim(&temp);
	if (ft_strlen(temp) <= 1)
		ex_msg("Error. Not valid texture");
	if (curr_str[0] == 'N' && curr_str[1] == 'O')
		f_data->texture_arr[0] = ft_strdup(temp);
	else if (curr_str[0] == 'S' && curr_str[1] == 'O')
		f_data->texture_arr[1] = ft_strdup(temp);
	else if (curr_str[0] == 'W' && curr_str[1] == 'E')
		f_data->texture_arr[2] = ft_strdup(temp);
	else if (curr_str[0] == 'E' && curr_str[1] == 'A')
		f_data->texture_arr[3] = ft_strdup(temp);
	else
		ex_msg("Error. Not valid texture");
	f_data->flag_textures += 1;
	free(temp);
	if (f_data->flag_textures == 4 && check_t_fornull(f_data))
		ex_msg("Error. Not valid texture");
}
