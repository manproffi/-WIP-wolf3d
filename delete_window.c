/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:31:01 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/17 19:31:03 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

void	delete_window(t_win *sdl)
{
	// SDL_DestroyTexture(tex);
	// printf("asdfasdfjashhiahflk\n");
	SDL_FreeSurface(sdl->surface);
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	// SDL_Quit();
}



