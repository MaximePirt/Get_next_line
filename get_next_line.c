/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:52 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/27 20:08:02 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_readline(int fd, char *res, char *tamp)
{
	int		i;
	char	*buff;

	i = 0;
	while (!ft_check(res, '\0') && !ft_check(res, '\n'))
	{
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!ft_check(buff, '\n'))
			i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			buff = NULL;
			break ;
		}
		res = ft_strjoin(res, buff);
		free(buff);
		buff = NULL;
	}
	if ((ft_check(res, '\n') && !ft_check(res, '\0')) && buff)
		lastfill(buff, tamp);
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
	{
		
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*tamp;
	int			i;

	// char		*buff;
	i = 0;
	if (fd < 0)
		return (NULL);
	if (!tamp)
		tamp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	res = ft_strjoin(res, tamp);
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
	// if (ft_check(res, '\0'))
	// {
	// 	free(tamp);
	// 	tamp = NULL;
	// }
	// if (!ft_strlen(res))
	// {
	// 	if (tamp)
	// 	{
	// 		free(tamp);
	// 		tamp = NULL;
	// 	}
	// 	free(res);
	// 	res = NULL;
	// 	return (NULL);
	// }
	return (res);
}

// int	main(void)
// {
// 	int fd = open("gnlTester/files/empty", O_RDONLY);
// 	// int fd = -1;
// 	char *line;

// 	if (fd < 0)
// 		return (-1);
// 			line = get_next_line(fd);
// 	printf("%s", line);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
