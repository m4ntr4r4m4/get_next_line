/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:29:13 by ahammoud          #+#    #+#             */
/*   Updated: 2022/01/08 12:30:04 by ahammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
	s = str;
}

int	ft_chr(char *s, int c)
{
	int		i;
	int		j;

	if (!s)
		return (0);
	j = -1;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == c)
			j = i;
		i--;
	}
	if (j == -1)
		return (0);
	return (j);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	if (!src && !dst)
		return (NULL);
	dest1 = dst;
	src1 = src;
	i = 0;
	while (i < n && (dest1[i] || src1[i]))
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	dest = NULL;
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	if (j != 0 || i != 0 || (char)s1[i] == '\0' || (char)s2[i] == '\0')
	{
		dest = malloc((j + i + 1) * sizeof(char));
		if (!dest)
			return (NULL);
		ft_memcpy(dest, s1, i);
		ft_memcpy(&dest[i], s2, j);
		dest[i + j] = '\0';
	}
	free(s1);
	return (dest);
}
