/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:21:50 by wcollen           #+#    #+#             */
/*   Updated: 2022/11/09 21:27:03 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	10000000
#endif

char	*return_str(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = ft_substr(str, 0, i);
	return (ret);
}

char	*return_rem(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	ret = ft_substr(str, i, ft_strlen(str));
	free(str);
	return (ret);
}

char	*add_buf(char *remainder, char *buf, int fd)
{
	int	n_bytes;

	n_bytes = 1;
	while (n_bytes != 0 && ft_strchr((const char *)remainder, '\n') == NULL)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[n_bytes] = '\0';
		if (!remainder)
			remainder = ft_substr(buf, 0, n_bytes);
		else
			remainder = gnl_ft_strjoin(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rem_array[1024];
	char		*ret_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rem_array[fd] = add_buf(rem_array[fd], buf, fd);
	if (!rem_array[fd] || rem_array[fd][0] == '\0')
	{
		free(rem_array[fd]);
		rem_array[fd] = 0;
		return (NULL);
	}
	ret_str = return_str(rem_array[fd]);
	if (!ret_str || ret_str[0] == '\0')
	{
		free(ret_str);
		return (NULL);
	}
	rem_array[fd] = return_rem(rem_array[fd]);
	return (ret_str);
}
