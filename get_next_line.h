/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:46 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/24 01:07:09 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Buffer size
# define BUFFER_SIZE 42

// External Libs
# include <unistd.h>
# include <stdlib.h>

//main file
char	*get_next_line(int fd);
char	*ft_parsing(char *buff);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *tamp);

// GNL utils
char	*firstfill(char *tamp, char *res);
char	*secondfill(char *buff, char *res);
char	*lastfill(char *buff, char *tamp);
char	*ft_cleantamp(char *tamp, int i);

#endif