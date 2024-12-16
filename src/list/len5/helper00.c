/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:31 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 18:11:04 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

int	case_func_xxxoo(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int	case_func_xxoxo(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int	case_func_xoxxo(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 1, pop(node_a, 0));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, RRA);
	push(ops, PB);
	push(ops, SA);
	push(ops, PB);
	return (0);
}

int	case_func_oxxxo(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int	case_func_xxoox(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	insert(node_b, 0, pop(node_a, 0));
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}
