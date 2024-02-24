/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:43 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/24 01:03:03 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *tamp)
{
	int	i;

	i = 0;
	while (tamp[i])
		i++;
	return (i);
}

int	ft_check(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	mallocsize;
	int		i;

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

char	*get_next_line(int fd)
{
	char		*buff;
	char		*res;
	static char	*tamp;
	int			i;

	i = 0;
	if (!tamp)
		tamp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE +1));
	firstfill(tamp, res);
	if (!ft_check(res))
		i += read(fd, buff, BUFFER_SIZE);
	secondfill(buff, res);
	lastfill(buff, tamp);
	free(buff);
	if (!ft_strlen(res))
	{
		free(tamp);
		tamp = NULL;
		free(res);
		return (NULL);
	}
	return (res);
}

#include <fcntl.h>
#include <stdio.h>


int main ()
{
	int fd = open("Notes2.txt", O_RDONLY);
	int	i = 0;
	char *line;

	if (fd < 0)
		return (-1);
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);		
		i++;
	}
	close(fd);
	return(0);
}