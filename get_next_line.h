/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:08:30 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/28 20:38:04 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
 
int get_next_line(const int fd, char **line);

#endif
