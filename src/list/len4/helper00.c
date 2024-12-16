/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:02:41 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 16:03:01 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

/// rotate
static int len4_case_0(t_node **node_a, t_node **ops)
{
	pop(node_a, 0);
	if (push(ops, PB))
		return (1);
	return (0);
}

static int len4_case_1(t_node **node_a, t_node **ops)
{
	if (push(node_a, pop(node_a, 0)))
		return (1);
	pop(node_a, 0);
	if (push(ops, RA))
		return (1);
	if (push(ops, PB))
		return (1);
	return (0);
}

static int len4_case_2(t_node **node_a, t_node **ops)
{
	if (push(node_a, pop(node_a, 0)))
		return (1);
	if (push(node_a, pop(node_a, 0)))
		return (1);
	pop(node_a, 0);
	if (push(ops, RA))
		return (1);
	if (push(ops, RA))
		return (1);
	if (push(ops, PB))
		return (1);
	return (0);
}

static int len4_case_3(t_node **node_a, t_node **ops)
{
	if (insert(node_a, 0, pop(node_a, len(*node_a) - 1)))
		return (1);
	pop(node_a, 0);
	if (push(ops, RRA))
		return (1);
	if (push(ops, PB))
		return (1);
	return (0);
}

void set_func_00(int (*func[4])(t_node **node_a, t_node **ops))
{
	func[0] = len4_case_0;
	func[1] = len4_case_1;
	func[2] = len4_case_2;
	func[3] = len4_case_3;
}
