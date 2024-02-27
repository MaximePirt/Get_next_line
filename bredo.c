/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bredo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:52 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/27 15:27:32 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *tamp)
{
	int	i;

	i = 0;
	while (tamp[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	mallocsize;
	size_t	i;

	if (count <= 0 || size <= 0)
		return (malloc(0));
	if (65535 / count < size)
		return (NULL);
	mallocsize = count * size;
	tmp = malloc(mallocsize);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < mallocsize)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

int	ft_check(char *res, char c)
{
	int	i;
	int	a;

	a = ft_strlen(res);
	i = 0;
	if (!a)
		return (0);
	while (i != a)
	{
		if (res[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*lastfill(char *buff, char *tamp)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	while (tamp[a])
		a++;
	while (buff[i])
	{
		tamp[a] = buff[i];
		i++;
		a++;
	}
	tamp[a] = '\0';
	return (tamp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*res;
	static char	*tamp;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	if (!tamp)
		tamp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_strjoin(res, tamp);
	while (!ft_check(res, '\0') && !ft_check(res, '\n'))
	{
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!ft_check(buff, '\n'))
			i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			break ;
		}
		res = ft_strjoin(res, buff);
		free(buff);
		buff = NULL;
	}
	if ((ft_check(res, '\n') && !ft_check(res, '\0')) && buff)
		lastfill(buff, tamp);
	else if (ft_check(res, '\0'))
	{
		free(tamp);
		tamp = NULL;
	}
	if (!ft_strlen(res))
	{
		if (tamp)
		{
			free(tamp);
			tamp = NULL;
		}
		free(res);
		return (NULL);
	}
	return (res);
}

int	main(void)
{
	int fd = open("41_no_nl", O_RDONLY);
	char *line;

	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}