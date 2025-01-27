/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_helper01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:21:47 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 18:25:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#include "optimizer/opt.h"
#include "merge_sort_helper.h"

int	init_sort(t_node **f, t_node **t, char f_f, t_node **ops)
{
	if (get_elem(*f, 0) < get_elem(*f, len(*f) - 1))
	{
		if (push_end(f, t, f_f, ops))
			return (1);
	}
	else
	{
		if (push_head(f, t, f_f, ops))
			return (1);
	}
	return (0);
}

int	get_min_exclude_minus(int ex[6], int *umin)
{
	int	i;

	i = 0;
	*umin = 0;
	while (i < 6)
	{
		if (0 < ex[i] && ex[i] < ex[*umin])
			*umin = i;
		else if (ex[*umin] < 0 && 0 < ex[i])
			*umin = i;
		i += 1;
	}
	if (ex[*umin] < 0)
		return (1);
	return (0);
}

static void	set_func(\
int (*func[6])(t_node **f, t_node **t, char f_f, t_node **ops))
{
	func[0] = push_head;
	func[1] = push_end;
	func[2] = push_second;
}

static void	set_ex(int ex[6], t_node **f, t_node **t, int i)
{
	int	j;

	j = 0;
	while (j < 6)
	{
		ex[j] = -1;
		j += 1;
	}
	ex[0] = (get_elem(*t, 0) - get_elem(*f, 0)) * i;
	ex[1] = (get_elem(*t, 0) - get_elem(*f, len(*f) - 1)) * i;
	if (1 < len(*f))
		ex[2] = (get_elem(*t, 0) - get_elem(*f, 1)) * i;
}

/// @brief 
/// @param f from
/// @param t to
int	move_stack(t_node **f, t_node **t, char f_f, t_node **ops)
{
	int	i;
	int	ex[6];
	int	umin;
	int	(*func[6])(t_node **f, t_node**t, char f_f, t_node **ops);

	if (init_sort(f, t, f_f, ops))
		return (1);
	i = 1;
	set_func(func);
	while (*f != NULL)
	{
		set_ex(ex, f, t, i);
		if (get_min_exclude_minus(ex, &umin))
			i *= -1;
		else
		{
			if (func[umin](f, t, f_f, ops))
				return (1);
		}
	}
	return (0);
}
