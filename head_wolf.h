/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_wolf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:08:52 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/03 17:08:54 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_WOLF_H
# define HEAD_WOLF_H

# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "libft/libft.h"
# include "ft_printf/printhead.h"
# include "head_wolf_struct.h"

# define WIDTH 1000
# define HEIGHT 1000

void	del_list_list(t_list **list);

t_list	*input_information(char const *argv[]);
t_list	*read_from_file(char const *argv[]);
void	start_work_with_map(t_list *list);
void	del_mass(t_player *pl);
void	start_loop(t_player *pl, t_win *sdl);





void	delete_window(t_win *sdl);
void	create_window(t_win *sdl);

void 	loop(t_player *pl, t_win *sdl);
void	add_color(int x, t_player *pl, t_win *sdl);


 
#endif
