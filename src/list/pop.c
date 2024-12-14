/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:32 by tmuranak          #+#    #+#             */
/*   Updated: 2024/11/07 21:32:20 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "private_list.h"

#include "../../src/swap/swap.h"
#include "../../src/output/output.h"
#include <stdlib.h>


/**
 * pub pop
 * @brief free: not required(depend on \`pop_index_elem\` function.
 *        but buff is freed by this funcction)
 * return head data and remove it
 * 
 */
int	pop(t_node **node_p_p, int index)
{
	int		rvalue;
	t_node	*head_p;

	head_p = pop_index_elem(node_p_p, index);
	rvalue = head_p->i32_data;
	free(head_p);
	return (rvalue);
}

/**
 * pub pop_elem
 * @brief free:required
 * @param node_p_p 
 */
t_node	*pop_elem(t_node **node_p_p)
{
	t_node	*head_p;

	head_p = *node_p_p;
	if (head_p == NULL)
		return (NULL);
	*node_p_p = head_p->back_p;
	if (head_p -> back_p != NULL)
	{
		head_p->back_p->pre_p = NULL;
		head_p->back_p = NULL;
	}
	return (head_p);
}


/// @brief you must free returned object by yourself
///        values outside the range are undefined
/// @param node_p_p 
/// @param index 
/// @return 
t_node	*pop_index_elem(t_node **node_p_p, int index)
{
	t_node	*r_node;
	t_node	*first_node;

	if (index == 0)
		return (pop_elem(node_p_p));
	first_node = *node_p_p;
	r_node = get_raw_ptr(node_p_p, index);
	r_node->pre_p->back_p = r_node->back_p;
	if (r_node->back_p != NULL)
		r_node->back_p->pre_p = r_node->pre_p;
	r_node->pre_p = NULL;
	r_node->back_p = NULL;
	*node_p_p = first_node;
	return (r_node);
}

