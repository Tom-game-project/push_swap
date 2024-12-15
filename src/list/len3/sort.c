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

#include "len3_helper.h"

#define LEN3_MAX 3

void set_arr(t_node *origin_node_a, int target_node_a[LEN3_MAX])
{
	int i;

	i = 0;
	while (i < LEN3_MAX)
	{
		target_node_a[i] = get_elem(origin_node_a, i);
		i += 1;
	}
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

int len3_sort_base(t_node **node_a, t_node **ops, int base)
{
	int arr[LEN3_MAX];
	void (*func[3][3])(t_node **ops);

	set_arr(*node_a, arr);
	set_len3_func(func);
	func[arr[0] - base][arr[1] - base](ops);
	return (0);
}

/// ここでスタックAを表す引数は、リストではなく配列です
int len3_sort(t_node **node_a, t_node **node_b, t_node **ops)
{
	(void) node_b;

	return len3_sort_base(node_a, ops, 1);
}

