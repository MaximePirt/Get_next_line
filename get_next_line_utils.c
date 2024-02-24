/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:40 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/24 01:04:19 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*firstfill(char *tamp, char *res)
{
	int	i;

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

char	*secondfill(char *buff, char *res)
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

char	*ft_cleantamp(char *tamp, int i)
{
	int	a;
	int	j;

	a = ft_strlen(tamp);
	j = 0;
	while (tamp[j])
	{
		if (i > a - 1)
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
	return (tamp);
}
