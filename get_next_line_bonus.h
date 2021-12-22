#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
char *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_substr(char *s, unsigned int start, size_t len);
int     ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
int	ft_chr(char	*s, int	c);
#endif
