/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:51:07 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/09 10:44:00 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symb)
{
	int	i;

	i = 0;
	while (str[i] != (unsigned char)symb)
	{
		if (str[i] == '\0')
			return ((void *)0);
		i++;
	}
	return ((char *)&str[i]);
}
