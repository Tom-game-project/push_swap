/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:34 by tmuranak          #+#    #+#             */
/*   Updated: 2024/11/07 21:31:45 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../../src/output/output.h"
#include "list.h"

/// {1, 2, 3} is sorted
/// nop
void len3_0_1(t_node **ops)
{
	(void) ops;
}

/// {1, 3, 2}
void len3_0_2(t_node **ops)
{
	push(ops, SA);
	push(ops, RA);
}

/// {2, 1, 3}
void len3_1_0(t_node **ops)
{
	push(ops, SA);
}

/// {2, 3, 1}
void len3_1_2(t_node **ops)
{
	push(ops, RRA);
}

/// {3, 1, 2}
void len3_2_0(t_node **ops) 
{
	push(ops, RA);
}

/// {3, 2, 1}
void len3_2_1(t_node **ops) 
{
	push(ops, SA);
	push(ops, RRA);
}

void set_len3_func(void (*func[3][3])(t_node **ops))
{
	func[0][0] = NULL;
	func[0][1] = len3_0_1;
	func[0][2] = len3_0_2;
	func[1][0] = len3_1_0;
	func[1][1] = NULL;
	func[1][2] = len3_1_2;
	func[2][0] = len3_2_0;
	func[2][1] = len3_2_1;
	func[2][2] = NULL;
}

/// ここでスタックAを表す引数は、リストではなく配列です
int len3_sort(int node_a[3], t_node **ops)
{
	void (*func[3][3])(t_node **ops);

	set_len3_func(func);
	func[node_a[0] - 1][node_a[1] - 1](ops);
	return (0);
}
