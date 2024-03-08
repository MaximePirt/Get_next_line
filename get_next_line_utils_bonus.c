/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:40 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/08 12:46:49 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *tamp)
{
	size_t	i;

	i = 0;
	while (tamp[i])
		i++;
	return (i);
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

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	mallocsize;
	size_t	i;

	if (count <= 0 || size <= 0)
		return (malloc(0));
	// if (2147483647 / count < size)
	// 	return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)ft_calloc((s1_len + s2_len + 1), 1);
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
		dst[i + s1_len] = s2[i];
		i++;
	}
	dst[i + s1_len] = s2[i];
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
