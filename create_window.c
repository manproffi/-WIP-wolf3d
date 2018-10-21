/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:14:34 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/17 19:14:35 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

void 	error_sdl_massage()
{
	printf("%s\n", SDL_GetError());
		// return 1;
}



void create_window(t_win *sdl)
{
	// if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		//return error_sdl_massage();

	if (!(sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000, SDL_WINDOW_OPENGL)))
		return error_sdl_massage();
	unsigned int window_id;
 	if ((window_id = SDL_GetWindowID(sdl->win)) == 0)
		return error_sdl_massage();
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return error_sdl_massage();



	// SDL_Surface *bmp = SDL_LoadBMP("picture1.bmp");
	// if (bmp == NULL)
	// {
	// 	printf("%s\n", SDL_GetError());
	// 	return ;
	// }

	// SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl->ren, bmp);
	// SDL_FreeSurface(bmp);
	// 	if (tex == NULL)
	// {
	// 	printf("%s\n", SDL_GetError());
	// 	return ;
	// }
	
	// SDL_RenderClear(sdl->ren);
	// SDL_RenderCopy(sdl->ren, tex, NULL, NULL);
	// SDL_RenderPresent(sdl->ren);

	// SDL_Delay(5000);


	// SDL_DestroyTexture(tex);


	
	// SDL_DestroyRenderer(sdl->ren);
	// SDL_DestroyWindow(sdl->win);
	// SDL_Quit();
}