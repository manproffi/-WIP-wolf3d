/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_wolf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:40:32 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/06 20:40:33 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_WOLF_STRUCT_H
# define HEAD_WOLF_STRUCT_H

# include "SDL.h"
# include "SDL_image.h"

typedef struct		s_player
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	Uint32			new_time;
	Uint32			old_time;
	int				**mass;
	int				len;
	double			x_camera;
	double			ray_x_dir;
	double			ray_y_dir;
	int				x_map;
	int				y_map;
	double			side_x_dist;
	double			side_y_dist;
	double			delta_x_dist;
	double			delta_y_dist;
	double			perp_wall_dist;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;

	double			frame_time;
	double			move_speed;
	double			rot_speed;


}					t_player;


typedef	struct 		s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	int				loop;


}					t_win;


#endif
