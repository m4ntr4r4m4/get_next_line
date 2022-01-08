/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:21:01 by ahammoud          #+#    #+#             */
/*   Updated: 2022/01/08 12:25:00 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_res(char *line)
{
	int		i;
	char	*res;

	res = NULL;
	if (line[0] == '\0')
	{
		free(line);
		return (0);
	}
	i = ft_chr(line, '\n');
	if (i || line[0] == '\n')
		res = ft_strjoin(res, &line[i + 1]);
	free(line);
	return (res);
}

char	*get_line(int fd, char *res)
{
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	i = 1;
	while (!ft_chr(res, '\n') && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		res = ft_strjoin(res, buff);
		if (res[0] == '\n')
			break ;
	}
	free(buff);
	return (res);
}

char	*get_first(char	*src)
{
	size_t	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	while (str[i])
		str[i++] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*res[100];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res[fd] = get_line(fd, res[fd]);
	if (res[fd] == NULL)
		return (NULL);
	line = get_first(res[fd]);
	res[fd] = save_res(res[fd]);
	if (line[0] == '\0')
	{
		free(line);
		free(res[fd]);
		return (NULL);
	}
	return (line);
}
