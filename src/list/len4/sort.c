/*************************************************************************** */
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

#include "../list.h"
#include "../len3/len3.h"
#include "len4_helper.h"


#define LEN4_MAX 4
#define LEN3_MAX 3

/// 4のindexを見つけます
int find_4_index(t_node *node_a)
{
	int i;

	i = 0;
	while (i < LEN4_MAX)
	{
		if (get_elem(node_a, i) == LEN4_MAX)
			return (i);
		i += 1;
	}
	return (-1);
}

/// 
/// 4抜きの長さ3の配列をセットする
void set_arr_without_4(t_node *origin_node_a, int target_node_a[LEN3_MAX])
{
	int i;

	i = 0;
	while (i < LEN3_MAX)
	{
		target_node_a[i] = get_elem(origin_node_a, i);
		i += 1;
	}
}

/// **紛らわしいから注意**
/// 引数は**リスト**!
int len4_sort(t_node **node_a, t_node **ops)
{
	void (*func[4])(t_node **node_a,t_node **ops);

	if (is_sorted(*node_a))
		return (0);
	set_func_00(func);
	func[find_4_index(*node_a)](node_a, ops);
	// 4をスタックbに移し替えたあとのstackaの状態（３つの要素が存在する状態でソートする）
	len3_sort(node_a, ops);
	push(ops, PA);
	push(ops, RA);
	optimize_ops(ops);
	return (0);
}
