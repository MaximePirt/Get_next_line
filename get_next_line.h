/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:46 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/18 22:30:46 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Buffer size

# define BUFFER_SIZE 42
//
//
// External Libs
#include <unistd.h>
#include <stdlib.h>

//main function
char	*get_next_line(int fd);

#endif