/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:52 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/28 08:40:12 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_cleantamp(char *tamp, int i)
{
	int a;
	int j;

	a = ft_strlen(tamp)+2;
	j = 0;
	while (tamp[j] && j < i-2)
	{
		if (tamp[j+(a-i)])
			tamp[j] = tamp[j+(a-i)];
		else if (tamp[i+1])
			tamp[j] = tamp[j+1];
		j++;
	}
	while (tamp[j])
	{
		tamp[j] = '\0';
		j++;
	}
	// printf("Voicitamp\n%s\n", tamp);
	return(tamp);
}

void firstfill(char *tamp, char *res)
{
	int i;
	i = 0;
	while (tamp[i] != '\n' && tamp[i])
	{
		res[i] = tamp[i];
		i++;
	}
	res[i] = tamp[i];
	i++;
	ft_cleantamp(tamp, i);
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
			break ;
		res = ft_strjoin(res, buff);
	}
	if ((ft_check(res, '\n') && !ft_check(res, '\0')) && buff)
		lastfill(buff, tamp);
	free(buff);
	buff = NULL;
	return (res);
}

int	ft_result_sort(char *res, char *tamp)
{
	if (ft_check(res, '\0'))
	{
		free(tamp);
		tamp = NULL;
	}
	if (!ft_strlen(res))
		return (-1);
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
	if (i == -1)
	{
		if (tamp)
		{
			free(tamp);
			tamp = NULL;
		}
		free(res);
		res = NULL;
		return (NULL);
	}
	return (res);
}

int	main(void)
{
	int fd = open("gnlTester/files/41_no_nl", O_RDONLY);
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
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}