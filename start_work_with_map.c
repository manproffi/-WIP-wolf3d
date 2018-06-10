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


	////***********////
	// i = -1;
	// while (++i < pl->len)
	// {
	// 	j = -1;
	// 	while (++j < pl->len)
	// 		printf("%d ", pl->mass[i][j]);
	// 	printf("\n");
	// }

	// printf("%f %f\n", pl->x_pos, pl->y_pos);






}


void	start_work_with_map(t_list *list)
{
	t_player	pl;

	pl.x_pos = 0.0;
	pl.y_pos = 0.0;
	pl.x_dir = -1.0;
	pl.y_dir = 0.0;
	pl.x_plane = 0.0;
	pl.y_plane = 0.66;
	// pl.new_time = clock();
	pl.old_time = 0;

	find_player_position_and_create_mass(list, &pl);
	// printf("x= %f y= %f\n", pl.x_pos, pl.y_pos);
	if (pl.x_pos == 0 && pl.y_pos == 0)
		printf("%s\n", "ERROR: no start position for player");
	else
	{
		create_window(&pl);
		// printf("asdfasdfasd\n");
		pl.new_time = clock();
		start_loop(&pl);
		// mlx_loop(win->mlx);
		// printf("END!!!\n");
	}
	mlx_loop(pl.mlx);

	del_mass(&pl);




}
