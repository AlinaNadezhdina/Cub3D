/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:22:35 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:09:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture_paths(t_img *img)
{
	int	i;

	i = -1;
	while (img && ++i < 4)
	{
		if (img->tex_path[i] != NULL)
		{
			free(img->tex_path[i]);
			img->tex_path[i] = NULL;
		}
	}
}

char	*ft_free_array(char ***arr, unsigned int allocated)
{
	unsigned int	i;
	unsigned int	current;

	current = 1;
	if (*arr == NULL)
		return (NULL);
	i = 0;
	while (i < allocated + current)
	{
		if ((*arr)[i] != NULL)
		{
			free((*arr)[i]);
			(*arr)[i] = NULL;
		}
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

void	free_all(t_data *data)
{
	free_texture_paths(&data->img);
	ft_free_array(&data->map->lines, data->map->width);
}
