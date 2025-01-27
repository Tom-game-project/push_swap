/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:18 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:46:45 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	get_elem(t_node *node_p, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i += 1;
		node_p = node_p -> back_p;
	}
	return (node_p -> i32_data);
}

t_node	*get_ptr(t_node *node_p, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i += 1;
		if (node_p == NULL)
			return (NULL);
		node_p = node_p -> back_p;
	}
	return (node_p);
}

t_node	*get_raw_ptr(t_node **node_p_p, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i += 1;
		if (*node_p_p == NULL)
			return (NULL);
		*node_p_p = (*node_p_p)->back_p;
	}
	return (*node_p_p);
}
