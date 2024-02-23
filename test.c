/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:42:31 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/23 06:35:41 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char    *ft_setamp (int a, char *tamp)
{
    int i;

    i = 0;
    while (tamp[i])
    {
        if (tamp[i+a])
            tamp[i] = tamp [i+a];
        else if (tamp[i+1])
            tamp[i] = tamp[i+1];
        i++;
    }
    return(tamp);
}

char	*ft_parsing(char *buff)
{
	char *res;
	static char *tamp;
	int i;
	int a;
	int z;

	z = 0;
	i = 0;
	a = 0;
	if(!tamp)
		tamp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	// printf("\ntampon c est\n%s\n", tamp);

	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (res[z] != '\n' || res[z] != '\0')
    {
        if (tamp[i])
        {
                // printf("ok");
            while (tamp[i])
		    {
				if (tamp[i] == '\n')
				{
					res[z] = tamp[i];
					break;
				}
		    	res[z] = tamp[i];
		    	i++;
				z++;
                // printf("OKTAMP");
				// printf("TAMPCLEAR");
		    }
			ft_setamp(i, tamp);
        }
        if (res[z] == '\n')
			break;
		while (buff[a] != '\0' && buff[a] != '\n')
        {
			// printf("OKBUFF");
            res[z] = buff[a];
            a++;
            z++;
		}
		res[z] = buff[a];
		 break;
    }
	while (res[z] == '\n' && buff[a])
    {
		tamp[i] = buff[a];
		i++;
		a++;
	}
	// printf("\nTamp fin fonction \n%s \n", tamp);
	return(res);
}
