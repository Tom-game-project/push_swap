/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:41 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:40:25 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>


/// @brief  node_p_p[index] = value
/// @param node_p_p 
/// @param index 
/// @param value 
void	set_num(t_node **node_p_p, int index, int value)
{
	if (index == len(*node_p_p))
		push(node_p_p, value);
	get_ptr(*node_p_p, index)->i32_data = value;
}
