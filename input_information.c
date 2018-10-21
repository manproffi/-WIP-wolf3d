/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:29:35 by sprotsen          #+#    #+#             */
/*   Updated: 2018/06/05 20:29:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_wolf.h"
#define SY(x) (x == '0' || x == '1' || x == '2' || x == '3' || x == 'p') ? 0 : 1
#define SX(x) (x == '4' || x == '5') ? 0 : 1


int 	check_simbols(t_list *list)
{
	t_list		*tmp;
	char		*str;

	tmp = list;

	while (tmp)
	{
		str = tmp->content;
		while (*str)
		{
			if (SY(*str) || SX(*str))
				return (1);
			str++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int 	check_first_and_last_line(char *first, char *last)
{
	while (*first)
	{
		if (*first++ != '1' || *last++ != '1')
			return (1);
	}
	return (0);
}

int 	check_len(int len, t_list **mass)
{
	int		i;
	char	*str;

	if (len != (int)ft_strlen(mass[0]->content))
		return (1);
	if (len < 3 || ft_strlen(mass[0]->content) < 3)
		return (1);
	i = -1;
	while (++i < len - 1)
	{
		if (ft_strlen(mass[i]->content) != ft_strlen(mass[i + 1]->content))
			return (1);
		str = mass[i]->content;
		if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
			return (1);
	}
	str = mass[i]->content;
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		return (1);
	if (check_first_and_last_line(mass[0]->content, mass[i]->content))
		return (1);
	return (0);
}

int 	validation(t_list *list)
{
	int 	i;
	int 	len;
	t_list	**mass;
	t_list	*tmp;

	len = ft_lstsize(list);
	if (len > 300)
		return (printf("ERROR: too big map\n"));
	mass = (t_list**)malloc(sizeof(t_list*) * len);
	i = -1;
	tmp = list;
	while (++i < len)
	{
		mass[i] = list;
		list = list->next;
	}
	if (check_len(len, mass) || check_simbols(tmp))
	{
		free(mass);
//		ft_printf(RED"Error: incorrect input format\n"RESET);
        printf("Error: incorrect input format\n");
		return (1);
	}
	free(mass);
	return (0);
}

t_list	*input_information(char const *argv[])
{
	t_list 	*list;

	list = NULL;
	list = read_from_file(argv);
	if (validation(list))
	{
		del_list_list(&list);
		return NULL;
	}


	// //****************//
	// t_list *tmp = list;
	// while (tmp)
	// {
	// 	printf("%s\n", tmp->content);
	// 	tmp = tmp->next;
	// }
	return (list);
}
