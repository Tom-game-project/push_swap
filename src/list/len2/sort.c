/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:01:46 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:52:15 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

int	len2_sort(t_node **node_a, t_node **node_b, t_node **ops)
{
	int		p;
	int		q;

	(void )	node_b;
	p = get_elem(*node_a, 0);
	q = get_elem(*node_a, 1);
	if (p > q)
	{
		if (push(ops, SA))
			return (1);
	}
	return (0);
}
