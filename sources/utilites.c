/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:36:00 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/10 10:09:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	ft_str_trim(char **str)
{
	int	len;

	len = ft_strlen(*str);
	while ((*str)[--len] == ' ')
		(*str)[len - 1] = '\0';
	while ((*str)[0] == ' ')
	{
		len = 0;
		while ((*str)[++len] != '\0')
			(*str)[len - 1] = (*str)[len];
		(*str)[len - 1] = '\0';
	}
}

char	*ft_strjoin_with_free(char *str1, char *str2, int free_1, int free_2)
{
	char	*result;

	if (! str1 && ! str2)
		return (NULL);
	else if (!str1)
		result = ft_strdup(str2);
	else if (!str2)
		result = ft_strdup(str1);
	else
		result = ft_strjoin(str1, str2);
	if (str1 && *str1 && free_1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2 && free_2)
	{
		free(str2);
		str2 = NULL;
	}
	return (result);
}

int	ft_count_str(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] != '\0' )
	{
		if (str[i] == '\n')
			res++;
		i++;
	}
	return (res + 1);
}

int	ft_count_str_array(t_file_data *f_data)
{
	int	i;

	i = 0;
	while (f_data->map_arr[i] != NULL)
		i++;
	return (i);
}

void	ex_msg(char *msg)
{
	printf("%s", msg);
	exit (1);
}
