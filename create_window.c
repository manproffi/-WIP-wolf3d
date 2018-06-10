/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:00:44 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/09 16:00:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"
#define CORNER all->rot_speed

int			key_function(int key, void *st)
{
	t_player	*all;

	all = (t_player*)st;
	if (key == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	if (key == 124)
	{
		double old_x_dir = all->x_dir;
		all->x_dir = all->x_dir * cos(CORNER) - all->y_dir * sin(CORNER);
		all->y_dir = old_x_dir * sin(CORNER) + all->y_dir * cos(CORNER);
		double old_x_plane = all->x_plane;
		all->x_plane = all->x_plane * cos(CORNER) - all->y_plane * sin(CORNER);
		all->y_plane = old_x_plane * sin(CORNER) + all->y_plane * cos(CORNER);
		start_loop(all);
	}
	if (key == 123)
	{
		double old_x_dir = all->x_dir;
		all->x_dir = all->x_dir * cos(-CORNER) - all->y_dir * sin(-CORNER);
		all->y_dir = old_x_dir * sin(-CORNER) + all->y_dir * cos(-CORNER);
		double old_x_plane = all->x_plane;
		all->x_plane = all->x_plane * cos(-CORNER) - all->y_plane * sin(-CORNER);
		all->y_plane = old_x_plane * sin(-CORNER) + all->y_plane * cos(-CORNER);
		start_loop(all);
	}
	if (key == 13)
	{
		// int index = all->x_pos + all->x_dir * all->move_speed;
		// if (index < all->len)
		// {
		// 	if (all->mass[(int)all->y_pos][index] == 0)
		// 		all->x_pos += all->x_dir * all->move_speed;
		// }
		// printf("%d\n", (int)(all->y_pos));
		printf("%d\n", (int)(all->x_pos + all->x_dir * all->move_speed));
		


		if(all->mass[(int)(all->y_pos)][(int)(all->x_pos + all->x_dir * all->move_speed)] == 0)
			all->x_pos = all->x_pos + all->x_dir * all->move_speed;
       
        if(all->mass[(int)(all->y_pos + all->y_dir * all->move_speed)][(int)(all->x_pos)] == 0)
        	all->y_pos = all->y_pos + all->y_dir * all->move_speed;
		
	}



	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

int		end(void)
{
	exit(0);
	return (0);
}

int		expose_hook(void *st)
{
	t_player	*all;

	all = (t_player*)st;
	mlx_clear_window(all->mlx, all->win);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

void	create_window(t_player *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "Wolf3D");
	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->str = mlx_get_data_addr(all->img, &(all)->bp, &(all)->sl, &(all)->end);
	// mlx_hook(all->win, 6, 0, mouse_move, all);
	mlx_hook(all->win, 2, 5, key_function, all);
	mlx_hook(all->win, 17, 1L << 17, end, NULL);
	// mlx_mouse_hook(all->win, mouse_hook, all);
	mlx_expose_hook(all->win, expose_hook, all);
	// mlx_loop(all->mlx);
}

