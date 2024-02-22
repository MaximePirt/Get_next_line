/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:43 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/22 02:44:26 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return(-1) ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);	
}

//  char	*ft_parsing (char *buff)
// {
// 	char *res;
// 	static char *tamp;
// 	int i;
// 	int a;

// 	i = 0;
// 	a = 0;
// 	if(!tamp)
// 		tamp = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if(tamp[i])
// 	{
// 		while (tamp[a] && (res[a] != '\n'))
// 		{
// 			res[a] = tamp[a];
// 			a++;
// 		}
// 	}
// 	if(res[a] != '\n')
// 	{
// 		while (buff[i] != '\0' && buff[i] != '\n')
// 			{
// 				res[a] = buff[i];
// 				i++;
// 				a++;
// 			}
// 		if (buff[i] == '\n')
// 		{
// 			res[a] = '\n';
// 			i++;char
// 			a = 0;
// 			while (buff[i] != '\0')
// 			{
// 				tamp[a] = buff[i];
// 				i++;
// 				a++;
// 			}
// 		}
// 	}
// 	return(res);
// }

char	*get_next_line(int fd)
{
    char *			res;
    static long		i;
    static char *	buff;

    i = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    i += read(fd, buff, BUFFER_SIZE);
	if (read < 0)
		return ("ERROR");

	res = ft_parsing(buff);
	// ft_putstr(res);
	printf("\nFin de fonction\n%s", res);
    free(buff);
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
	close(fd);
	return(0);
}