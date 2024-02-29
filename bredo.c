/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bredo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:52 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/29 20:18:45 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *tamp)
{
	size_t	i;

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
	{
		printf("COUCOU");
		return (NULL);
	}
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
	size_t		i;
	size_t s1_len;
	size_t s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)calloc((s1_len + s2_len + 1), 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		dst[i+s1_len] = s2[i];
		i++;
	}
	dst[i+s1_len] = s2[i];
	free(s1);
	return (dst);
}

char	*lastfill(char *buff, char *tamp)
{
	int	i;
	int	a;

	if (!tamp && !buff)
		return (NULL);
	else if (!tamp)
		return (buff);
	else if (!buff)
		return (tamp);
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

char *ft_cleantamp(char *tamp, int i)
{
	size_t j;
	size_t a;

	a = ft_strlen(tamp);
	j = 0;
	while (tamp[j] && j < (a-i))
	{
		tamp[j] = tamp[j+i];
		j++;
	}
	while (tamp[j])
	{
		tamp[j] = '\0';
		j++;
	}
	// tamp[j] = '\0';
	return(tamp);
}

void firstfill(char *tamp, char *res)
{
	size_t i;
	i = 0;
	while (tamp[i] != '\n' && tamp[i])
	{
		res[i] = tamp[i];
		i++;
	}
	if (tamp[i] == '\n')
	{
		res[i] = tamp[i];
		i++;
	}
	tamp = ft_cleantamp(tamp, i);
	return ;
}

char	*ft_readline(int fd, char *res, char *tamp)
{
	int		i;
	char	*buff;

	i = 0;
	while (!ft_check(res, '\0') && !ft_check(res, '\n'))
	{
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
			i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			buff = NULL;
			break ;
		}
		res = ft_strjoin(res, buff);
		if (((ft_check(res, '\n') || ft_check(res, '\0'))) && buff)
			lastfill(buff, tamp);
		free(buff);
		buff = NULL;
	}

	return (res);
}

int	ft_result_sort(char *res, char *tamp)
{
	if (!ft_strlen(res))
		return (-1);
	if (ft_check(res, '\0') || !ft_strlen(tamp))
	{
		if (tamp)
		return(1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*tamp;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	if (!tamp)
		tamp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	firstfill(tamp, res);
	res = ft_readline(fd, res, tamp);
	i = ft_result_sort(res, tamp);
	while (i == -1 || i == 1)
	{
		free(tamp);
		tamp = NULL;
		if (i == 1)
			break;
		free(res);
		res = NULL;
		return (NULL);
	}
	return (res);
}

int	main(void)
{
	int fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	char *line;

	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
