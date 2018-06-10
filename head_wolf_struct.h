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

typedef struct		s_player
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	clock_t			new_time;
	clock_t			old_time;
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
	/*
	** for mlx
	*/
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				bp;
	int				sl;
	int				end;
	int				a;
}					t_player;

// typedef	struct		s_win
// {
// 	void			*mlx;
// 	void			*win;
// 	void			*img;
// 	char			*str;
// 	int				bp;
// 	int				sl;
// 	int				end;
// 	int				a;
// }					t_win;

enum				e_colors
{
	C_RED = 0x0000ff,
	C_YELLOW = 0xffcc65,
	C_GREEN = 0x00ff00,
};

#endif
