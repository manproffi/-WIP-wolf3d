/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_work_with_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:46:58 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/06 20:46:59 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"
#define FIND_POS(x, i, j) (x == 'p' ? pl->x_pos = j, pl->y_pos = i : 0)

void	find_player_position_and_create_mass(t_list *list, t_player *pl)
{
	int		i;
	int		j;
	char 	*str;
	t_list 	*tmp;

	pl->len = ft_lstsize(list);
	pl->mass = (int**)malloc(sizeof(int*) * pl->len);
	i = -1;
	while (++i < pl->len)
		pl->mass[i] = (int*)malloc(sizeof(int) * pl->len);
	tmp = list;
	i = pl->len;
	while (tmp)
	{
		--i;
		j = -1;
		str = tmp->content;
		while (++j < pl->len)
		{
			pl->mass[i][j] = str[j] - '0';
			pl->mass[i][j] = pl->mass[i][j] == 64 ? 0 : pl->mass[i][j];
			FIND_POS(str[j], i, j); 
			// printf("%d ", pl->mass[i][j]);
		}
		// printf("\n");
		tmp = tmp->next;
	}
}


void	start_work_with_map(t_list *list)
{
	t_player	pl;
	t_win		sdl;

	pl.x_pos = 0.0;
	pl.y_pos = 0.0;
	pl.x_dir = -1.0;
	pl.y_dir = 0.0;
	pl.x_plane = 0.0;
	pl.y_plane = 0.66;
	pl.new_time = 0;

	find_player_position_and_create_mass(list, &pl);
	if (pl.x_pos == 0 && pl.y_pos == 0)
		printf("%s\n", "ERROR: no start position for player");
	else
	{
		create_window(&sdl);
		sdl.loop = 0;
		sdl.surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
		if (sdl.surface == NULL)
		{
			printf(RED"ERROR kngkdsfnk \n"RESET);
		}
		start_loop(&pl, &sdl);
		printf("****start loop\n");
		loop(&pl, &sdl);

		delete_window(&sdl);

	}
	

	del_mass(&pl);




}
