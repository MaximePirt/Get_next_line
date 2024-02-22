/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:51:24 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/22 21:39:27 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *get_next_line(int fd)
{
    char *buff;
    char *tamp;
    char *res;
    int i;


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