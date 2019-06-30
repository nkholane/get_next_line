/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:24:43 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/28 16:24:47 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int const fd, char **line)
{
    char buffer[2] = "";

    /* Allocate line memory if needed */
    if( !*line )
        *line = malloc(100 * sizeof(char));

    /* Blank out the line */
    *line[0] = '\0';

    while( read(fd, buffer, 1) > 0 ) {
        strncat(*line, buffer, 1);
        if( buffer[0] == '\n' )
            break;
    }

    return 0;
}
