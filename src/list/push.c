/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:39 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:38:40 by tmuranak         ###   ########.fr       */
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

/**
 * pub heappush
 * @brief free: required (depend on \`push\` function)
 */
int	heappush(t_node **parent_p, int i32_data)
{
	int		current_index;
	int		parent_index;
	t_node	*parent_node;

	push(parent_p, i32_data);
	put_str("pb\n");
	put_str("rb\n");
	current_index = len(*parent_p) - 1;
	while (0 < current_index)
	{
		parent_index = (current_index - 1) / 2;
		parent_node = get_ptr(*parent_p, parent_index);
		if (i32_data < parent_node -> i32_data)
		{   
			// swap current_index <-> parent_index
			oswap(parent_index, current_index, len(*parent_p));
			set_num(parent_p, current_index, parent_node -> i32_data);
			current_index = parent_index;
			continue ;
		}
		break ;
	}
	// swap_stack_b_0(current_index, parent_index);
	set_num(parent_p, current_index, i32_data);
	return (0);
}
