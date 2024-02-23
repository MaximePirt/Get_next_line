/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:51:24 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/23 07:59:18 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	return(tamp);

}

char *get_next_line(int fd)
{
    char *buff;
    static char *tamp;
    char *res;
    int i;
	int z;

	i = 0;
	// printf("Tampon \n%s\n", tamp);
	if (!tamp)
		tamp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buff = malloc(sizeof(char) * (BUFFER_SIZE +1));
	firstfill(tamp, res);
	// printf("Tampon apres changement  \n%s\n", tamp);
	// printf("res maintenant \n%s\n", res);
	z = ft_check(res);
	if (z == 0)
		i+=read(fd, buff, BUFFER_SIZE);
	secondfill(buff, res);
	lastfill(buff, tamp);
	// printf("Tampon final \n%s\n", tamp);
// printf("Resultat :\n%s\n", res);
printf("%s", res);
	// ft_putstr(res);
    return(res);
}


#include <fcntl.h>
int main ()
{
	int fd = open("Notes.txt", O_RDONLY);

	if (fd < 0)
		return (-1);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return(0);
}