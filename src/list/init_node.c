/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:21 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:47:23 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/// @brief return type Result<t_node,NULL>
/// @param i32_data 
/// @return 

/**
 * pub init_node
 * @brief free: required
 * 
 */
t_node	*init_node(int i32_data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->back_p = NULL;
	node->pre_p = NULL;
	node->i32_data = i32_data;
	return (node);
}
