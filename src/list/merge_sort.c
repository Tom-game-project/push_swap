/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:34 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 18:24:25 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort_helper.h"

int	merge_sort(t_node **node_a, t_node **node_b, t_node **ops)
{
	while (!is_sorted(*node_a))
	{
		if (move_stack(node_a, node_b, 'a', ops))
			return (1);
		if (move_stack(node_b, node_a, 'b', ops))
			return (1);
	}
	if (optimize_ops(ops))
		return (1);
	return (0);
}
