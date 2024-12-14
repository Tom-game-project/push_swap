/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:39 by tmuranak          #+#    #+#             */
/*   Updated: 2024/11/07 21:32:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

#include "../../src/swap/swap.h"
#include "../../src/output/output.h"

// test
#include <stdio.h>

/**
 * private get_back
 * @brief free: not required
 */
static t_node	*get_back(t_node *node_p)
{
	if (node_p == NULL)
		return (node_p);
	while (node_p -> back_p != NULL)
		node_p = node_p->back_p;
	return (node_p);
}

/** 
 * pub push
 * 
 * @brief free: required (depend on \`init_node\` function)
 * @param parent_p
 * @param i32_data 
 * @return
 */
int	push(t_node **parent_p, int i32_data)
{
	t_node	*back_node_p;
	t_node	*new_node_p;

	new_node_p = init_node(i32_data);
	if (new_node_p == NULL)
		return (1);
	back_node_p = get_back(*parent_p);
	if (back_node_p == NULL)
	{
		*parent_p = new_node_p;
		return (0);
	}
	back_node_p->back_p = new_node_p;
	new_node_p->pre_p = back_node_p;
	return (0);
}
