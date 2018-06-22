/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:06:01 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/18 21:06:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"
#define CORNER all->rot_speed




void	key_ivents(t_player *all, t_win *sdl)
{
	//printf("press key\n %d", sdl->e.key.keysym.sym);
      (void)all;
      (void)sdl;
      if (sdl->e.key.keysym.sym == SDLK_w) {
            if(all->mass[(int)(all->y_pos)][(int)(all->x_pos + all->x_dir * all->move_speed)] == 0)
                  all->x_pos = all->x_pos + all->x_dir * all->move_speed;
            if(all->mass[(int)(all->y_pos + all->y_dir * all->move_speed)][(int)(all->x_pos)] == 0)
                  all->y_pos = all->y_pos + all->y_dir * all->move_speed;
            start_loop(all, sdl);
      }
      if (sdl->e.key.keysym.sym == SDLK_s)
      {
            if(all->mass[(int)(all->y_pos)][(int)(all->x_pos + all->x_dir * all->move_speed)] == 0)
                  all->x_pos = all->x_pos - all->x_dir * all->move_speed;
            if(all->mass[(int)(all->y_pos + all->y_dir * all->move_speed)][(int)(all->x_pos)] == 0)
                  all->y_pos = all->y_pos - all->y_dir * all->move_speed;
            start_loop(all, sdl);
      }
      if (sdl->e.key.keysym.sym == SDLK_LEFT)
      {
            double old_x_dir = all->x_dir;
            all->x_dir = all->x_dir * cos(CORNER) - all->y_dir * sin(CORNER);
            all->y_dir = old_x_dir * sin(CORNER) + all->y_dir * cos(CORNER);
            double old_x_plane = all->x_plane;
            all->x_plane = all->x_plane * cos(CORNER) - all->y_plane * sin(CORNER);
            all->y_plane = old_x_plane * sin(CORNER) + all->y_plane * cos(CORNER);
            start_loop(all, sdl);
      }
      if (sdl->e.key.keysym.sym == SDLK_RIGHT)
      {
            double old_x_dir = all->x_dir;
            all->x_dir = all->x_dir * cos(-CORNER) - all->y_dir * sin(-CORNER);
            all->y_dir = old_x_dir * sin(-CORNER) + all->y_dir * cos(-CORNER);
            double old_x_plane = all->x_plane;
            all->x_plane = all->x_plane * cos(-CORNER) - all->y_plane * sin(-CORNER);
            all->y_plane = old_x_plane * sin(-CORNER) + all->y_plane * cos(-CORNER);
            start_loop(all, sdl);
      }


}





void loop(t_player *pl, t_win *sdl)
{
	(void)pl;

	while (!sdl->loop)
	{
		while (SDL_PollEvent(&(sdl->e)) != 0)
		{
                  if( sdl->e.type == SDL_QUIT )
                  {
                      sdl->loop = 1;
                  }
                  else if ( sdl->e.type == SDL_KEYDOWN )
                  {
                  	if (sdl->e.key.keysym.sym == SDLK_ESCAPE)
                  		sdl->loop = 1;
                  	else
                  		key_ivents(pl, sdl);
                  }
		}
	}
}

