/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:37 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 18:12:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

int	case_func_xoxox(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 1, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, SA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int	case_func_oxxox(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int	case_func_xooxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	push(node_a, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, RA);
	push(ops, PB);
	push(ops, PB);
	return (0);
}

int	case_func_oxoxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0));
	push(node_a, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, PB);
	push(ops, RA);
	push(ops, PB);
	return (0);
}

int	case_func_ooxxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, PB);
	push(ops, PB);
	return (0);
}
