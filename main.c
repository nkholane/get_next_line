/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:36:18 by nkholane          #+#    #+#             */
/*   Updated: 2019/07/03 16:57:30 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char *line;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	if (!argc)
		return (0);
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	return (0);
}
