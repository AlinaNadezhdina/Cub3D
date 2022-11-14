/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:26:19 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:06:40 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_pixels(t_img *img, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE_XPM)
	{
		j = 0;
		while (j < SIZE_XPM)
		{
			if (type == north)
				img->textures.north_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == east)
				img->textures.east_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == west)
				img->textures.west_wall[i][j] = my_mlx_pixel_get(img, i, j);
			else if (type == south)
				img->textures.south_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}

static int	get_wall_textures(t_data *data, t_img *img)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	while (i < 4)
	{
		img->textures.tex_ptr[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.tex_path[i], &width, &height);
		if (data->img.textures.tex_ptr[i] == NULL)
		{
			ft_putstr_fd(data->img.tex_path[i], 2);
			ft_putstr_fd(" : FAILURE_OF_MEMORY_ALLOCATION\n", 2);
			return (EXIT_FAILURE);
		}
		img->textures.tex_addr = mlx_get_data_addr(img->textures.tex_ptr[i],
				&img->bits_per_pixel, &img->line_length, &img->endian);
		if (img->textures.tex_addr == NULL)
			return (EXIT_FAILURE);
		get_wall_pixels(img, i);
		free(img->textures.tex_addr);
		img->textures.tex_addr = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_textures(t_data *data, t_validate *val)
{	
	t_img	*img;

	img = &data->img;
	img->tex_path[north] = val->wall.no;
	img->tex_path[east] = val->wall.ea;
	img->tex_path[west] = val->wall.we;
	img->tex_path[south] = val->wall.so;
	if (get_wall_textures(data, img) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
