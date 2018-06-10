/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:21:00 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/05 20:21:01 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

t_list	*read_from_file(char const *argv[])
{
	int		fd;
	char	*line;
	t_list	*list;

	list = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR input file");
		exit(1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstaddend(&list, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	close(fd);
	return (list);
}
