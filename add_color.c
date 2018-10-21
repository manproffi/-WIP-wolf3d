/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:56:56 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/19 19:56:58 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

static inline void      put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
      Uint32 *pixels;

      pixels = (Uint32 *)surface->pixels;
      pixels[(y * surface->w) + x] = pixel;
}

void	add_color(int x, t_player *pl, t_win *sdl)
{
	int 	y;
	// (void)sdl;
	// (void)x;
	Uint32 color; //= SDL_MapRGBA(sdl->surface->format, 0,255,0,255);

	if (pl->mass[pl->y_map][pl->x_map] == 1)
		color =  SDL_MapRGBA(sdl->surface->format, 0,255,0,255);
	else
		color = SDL_MapRGBA(sdl->surface->format, 0,125,0,255);

	y = -1;
	while (++y < pl->draw_start)
		put_pixel(sdl->surface, x, y, SDL_MapRGBA(sdl->surface->format, 255,255,0,255));

	y = pl->draw_start;
	



	printf("y=%d x=%d ++++%d %d*****\n", y, x, pl->draw_end, SDL_MapRGBA(sdl->surface->format, 0,255,0,0));
	while (y < pl->draw_end)
	{
		// printf("***** %d %d\n", x, y);
		
		put_pixel(sdl->surface, x, y, color);
		++y;
	}

	while (y < HEIGHT)
		put_pixel(sdl->surface, x, y++, SDL_MapRGBA(sdl->surface->format, 0,255, 255,255));
	
	
}
