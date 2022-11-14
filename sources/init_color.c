/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:32:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:15:01 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_num(char *color, int k, int *i)
{
	int		res;
	char	num[256];

	while (color[*i] && color[*i] != ',')
	{
		if (ft_isdigit(color[*i]))
			num[k] = color[*i];
		else
			ex_msg("Error. Incorrect color2");
		(*i)++;
		k++;
	}
	num[k] = '\0';
	if (k == 0)
		ex_msg("Error. Incorrect color3");
	res = ft_atoi((const char *)num);
	if (res < 0 || res > 255)
		ex_msg("Error. Incorrect color4");
	return (res);
}

void	check_color(t_file_data *f_data, char *curr_str)
{
	int		j;
	int		i;
	char	*temp;

	temp = ft_strdup(&curr_str[1]);
	ft_str_trim(&temp);
	j = -1;
	i = 0;
	while (++j < 3)
	{
		if (curr_str[0] == 'F')
			f_data->f[j] = ft_num(temp, 0, &i);
		else if (curr_str[0] == 'C')
			f_data->c[j] = ft_num(temp, 0, &i);
		if (temp[i] && j < 2)
			i++;
		if (temp[i] && j == 2)
			ex_msg("Error. Incorrect colors5");
	}
	free(temp);
}

int	check_c_fornull(t_file_data *f_data)
{
	f_data->ii = -1;
	while (++(f_data->ii) < 2)
	{
		if (f_data->color_arr[f_data->ii] == NULL)
			return (1);
	}
	return (0);
}

void	init_color(t_file_data *f_data, char *curr_str)
{
	char	*temp;

	temp = ft_strdup(&curr_str[1]);
	ft_str_trim(&temp);
	if (ft_strlen(temp) <= 1)
		ex_msg("Error. Not valid color");
	if (curr_str[0] == 'F')
		f_data->color_arr[0] = ft_strdup(temp);
	else if (curr_str[0] == 'C')
		f_data->color_arr[1] = ft_strdup(temp);
	else
		ex_msg("Error. Not valid color");
	f_data->flag_colors += 1;
	free(temp);
	if (f_data->flag_colors == 2 && check_c_fornull(f_data))
		ex_msg("Error. Incorrect colors1");
}
