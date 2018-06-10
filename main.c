/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:08:30 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/03 17:08:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

int	main(int argc, char const *argv[])
{
	t_list		*list;


	list = NULL;
	if (argc == 2)
	{
		list = input_information(argv);

		// printf("%d\n", C_YELLOW & 255);
		// printf("%d\n", ((C_YELLOW >> 8) & 255));
		// printf("%d\n", ((C_YELLOW >> 16) & 255));
		

		//sleep(10);
		
		start_work_with_map(list);
		// sleep(3);
		



		del_list_list(&list);
	}
	else
		ft_printf("usage: ./wolf3d <map's name>\n");
	system("leaks -q wolf3d");
	return (0);
}