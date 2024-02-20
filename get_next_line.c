/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:43 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/20 13:15:37 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str)
	{
		write(1, str, 1);
		i++;
		str++;
	}
	return(i);
}

char *ft_parsing (char *buff)
{
	char *res;
	int i;
	
	i = 0;

	res =  malloc((BUFFER_SIZE + 1) * sizeof(char));;

	while (buff[i] != '\0' && buff[i] != '\n')
	{
		//write(1, &buff[i], 1);
		res[i] = buff[i];
		i++;
	}

	//write(1, "D", 1);
	return(res);
}

char	*get_next_line(int fd)
{
    char *			res;
    static long		i;
    char *			buff;

    i = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//while (buff[i] != '\0' || buff[i] != '\n') 
	//{
    i += read(fd, buff, BUFFER_SIZE);
	//}

	res = ft_parsing(buff);
	ft_putstr(res);
	//write(1, "o", 1);
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
	close(fd);
	return(0);
}