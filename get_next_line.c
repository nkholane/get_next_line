/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:24:43 by nkholane          #+#    #+#             */
/*   Updated: 2019/07/03 16:54:36 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_nextline(char **str, char **line, int fd, int reader)
{
	unsigned int	i;
	unsigned int	len;
	char			*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		len = i;
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (reader == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*arr_fd[200];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			res;

	if (fd < 0 || !line)
		return (-1);
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (arr_fd[fd] == NULL)
			arr_fd[fd] = ft_strnew(1);
		temp = ft_strjoin(arr_fd[fd], buf);
		free(arr_fd[fd]);
		arr_fd[fd] = temp;
		if (ft_strchr(arr_fd[fd], '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && (arr_fd[fd] == NULL || arr_fd[fd][0] == '\0'))
		return (0);
	return (ft_nextline(arr_fd, line, fd, res));
}
