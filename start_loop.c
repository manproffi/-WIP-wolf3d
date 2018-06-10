/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:56:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/07 20:56:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

void	vertical_line(int x, t_player *pl, int color)
{
	int 	i;

	i = pl->draw_start - 1;
	// printf("%d\n",  (char)color & 255);
	// printf("%d\n",  (char)(color >> 8) & 255);
	// printf("%d\n",  (char)(color >> 16) & 255);
	if (pl->side == 1)
		color = color / 2;
	// printf(">>>>>> %d %d\n", pl->draw_start, pl->draw_end);
	
	while (++i < pl->draw_end)
	{
		// if (i == 250)
			// printf("**** %d\n", x);
		

		// printf("**** %d -->>> %d\n", i, (i * WIDTH * 4 + x * 4));
		// printf("%d\n", (i * WIDTH * 4 + x * 4 + 2));
		// sleep(1);
		pl->str[i * WIDTH * 4 + x * 4 + 2] = (char)color & 255;
		pl->str[i * WIDTH * 4 + x * 4 + 1] = (char)(color >> 8) & 255;
		pl->str[i * WIDTH * 4 + x * 4 + 0] = (char)(color >> 16) & 255;
	}
}

void	color_and_draw(int x, t_player *pl)
{
	// printf("color_and_draw\n");
	if (pl->mass[pl->y_map][pl->x_map] == 1)
		vertical_line(x, pl, C_YELLOW);
	else if (pl->mass[pl->y_map][pl->x_map] == 2)
		vertical_line(x, pl, C_GREEN);
	else if (pl->mass[pl->y_map][pl->x_map] == 3)
		vertical_line(x, pl, C_RED);
	else
		vertical_line(x, pl, 0x00ff00);	
}

void	calculate_distance(t_player *pl)
{
	
	// printf("pl->x_map) --->>%d\n", pl->x_map);
	// printf("pl->x_pos) --->>%f\n", pl->x_pos);
	// printf("pl->x_step --->>%d\n", pl->x_step);
	// printf("pl->ray_x_ --->>%f\n", pl->ray_x_dir);

	if (pl->side == 0)
		pl->perp_wall_dist = (pl->x_map - pl->x_pos + (1 - pl->x_step) / 2) / pl->ray_x_dir;
	else
		pl->perp_wall_dist = (pl->y_map - pl->y_pos + (1 - pl->y_step) / 2) / pl->ray_y_dir;

	// printf("%f\n", pl->perp_wall_dist );
	// sleep(2);

	// printf(" pl->perp_wall_dist %f\n", pl->perp_wall_dist);
	pl->line_height = (int)(HEIGHT / pl->perp_wall_dist);

	// printf("pl->line_height %d \n",pl->line_height);
	pl->draw_start = -(pl->line_height) / 2 + HEIGHT / 2;
	if (pl->draw_start < 0)
		pl->draw_start = 0;
	pl->draw_end = pl->line_height / 2 + HEIGHT / 2;
	if (pl->draw_end >= HEIGHT)
		pl->draw_end = HEIGHT - 1;

	// printf("%d\n", pl->draw_start);
	// printf("%d\n", pl->draw_end);
	// sleep(2);
}

void loop_while(t_player *pl)
{
	while (pl->hit == 0)
	{
		if (pl->side_x_dist < pl->side_y_dist)
		{
			pl->side_x_dist += pl->delta_x_dist;
			pl->x_map += pl->x_step;
			pl->side = 0;
		}
		else
		{
			pl->side_y_dist += pl->delta_y_dist;
			pl->y_map += pl->y_step;
			pl->side = 1;
		}
		// printf("%d %d\n", pl->x_map, pl->y_map);
		if (pl->mass[pl->y_map][pl->x_map] > 0)
			pl->hit = 1;
	}
}


void	calculate_step_and_initial_side(t_player *pl)
{
	pl->hit = 0;
	if (pl->ray_x_dir < 0)
	{
		pl->x_step = -1;
		pl->side_x_dist = (pl->x_pos - pl->x_map) * pl->delta_x_dist;
	}
	else
	{
		pl->x_step = 1;
		pl->side_x_dist = (pl->x_map + 1.0 - pl->x_pos) * pl->delta_x_dist;
	}
	if (pl->ray_y_dir < 0)
	{
		pl->y_step = -1;
		pl->side_y_dist = (pl->y_pos - pl->y_map) * pl->delta_y_dist;
	}
	else
	{
		pl->y_step = 1;
		pl->side_y_dist = (pl->y_map + 1.0 - pl->y_pos) * pl->delta_y_dist;
	}
}

void	start_loop(t_player *pl)
{
	int		x;

	ft_bzero(pl->str, WIDTH * 4 * HEIGHT);
	x = -1;
	while (++x < WIDTH)
	{
		// printf("%d ", x);
		pl->x_camera = 2 * x / (double)WIDTH - 1;
		pl->ray_x_dir = pl->x_dir + pl->x_plane * pl->x_camera;
		pl->ray_y_dir = pl->y_dir + pl->y_plane * pl->x_camera;
		pl->x_map = (int)pl->x_pos;
		pl->y_map = (int)pl->y_pos;
		pl->delta_x_dist = fabs(1 / pl->ray_x_dir);
		pl->delta_y_dist = fabs(1 / pl->ray_y_dir);
		calculate_step_and_initial_side(pl);
		loop_while(pl);
		calculate_distance(pl);
		color_and_draw(x, pl);
	}
	pl->a = mlx_put_image_to_window(pl->mlx, pl->win, pl->img, 0, 0);
	pl->old_time = pl->new_time;
	// printf("%lu\n", pl->old_time);
	pl->new_time = clock();
	// printf("%lu\n", pl->new_time);
	pl->frame_time = (double)(pl->old_time - pl->new_time) / 500000.0;
	pl->move_speed = pl->frame_time * 0.0000000000001;
	printf("%f\n", pl->move_speed);
	pl->rot_speed = pl->frame_time * 3.0;


	// printf("%lu\n", clock()); 
}
