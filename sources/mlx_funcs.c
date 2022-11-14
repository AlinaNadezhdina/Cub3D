/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:39:05 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 12:01:28 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->textures.tex_addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	get_color(char c)
{
	int	color;

	if (c == '0')
		color = 0xFFFFFF;
	else if (c == '1')
		color = 0x008000;
	else
		color = 0;
	return (color);
}
