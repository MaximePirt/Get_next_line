/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:51:24 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/24 00:50:58 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	mallocsize;
	int i;

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

int ft_strlen(char *tamp)
{
	int i;

	i = 0;
	while (tamp[i])
		i++;
return (i);
}

int ft_check(char *res)
{
	int i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}
char *ft_cleantamp(char *tamp, int i)
{
	int a;
	int j;

	a = ft_strlen(tamp);
	j = 0;
	while (tamp[j])
	{
		if (i > a-1)
			tamp[j] = '\0';
		else if (tamp[i])
			tamp[j] = tamp[i];
		j++;
		i++;
	}
	while (tamp[j])
	{
		tamp[j] = '\0';
		j++;
	}
	return(tamp);
}

char *firstfill(char *tamp, char *res)
{
	int i;
	i = 0;
	while (tamp[i] != '\n' && tamp[i] != '\0')
	{
		res[i] = tamp[i];
		i++;
	}
	res[i] = tamp[i];
	i++;
	ft_cleantamp(tamp, i);
	return (res);
}

char *	secondfill(char * buff, char *res)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (res[i])
		i++;
	while (buff[a] != '\0' && buff[a] != '\n')
	{
		res[i] = buff[a];
		i++;
		a++;
	}
	res[i] = buff[a];
	return (res);
}

char *lastfill(char *buff, char *tamp)
{
	int i;
	int a;

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
	return(tamp);

}

char *get_next_line(int fd)
{
    char *buff;
	char *res;
    static char *tamp;
    int i;

	i = 0;
	if (!tamp)
		tamp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE +1));
	firstfill(tamp, res);
	if (!ft_check(res))
		i+=read(fd, buff, BUFFER_SIZE);
	secondfill(buff, res);
	lastfill(buff, tamp);
	free(buff);
	if (!ft_strlen(res))
	{
		free(tamp);
		tamp = NULL;
		free(res);
		return(NULL);
	}
    return(res);
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