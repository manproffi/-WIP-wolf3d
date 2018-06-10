/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:32:22 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/05 20:32:23 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
	}
}

void	del_mass(t_player *pl)
{
	int 	i;

	i = -1;
	while (++i < pl->len)
		free(pl->mass[i]);
	free(pl->mass);
}
