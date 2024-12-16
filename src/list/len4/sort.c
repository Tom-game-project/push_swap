/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:34 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 18:10:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"
#include "../len3/len3.h"
#include "len4_helper.h"

#define LEN4_MAX 4
#define LEN3_MAX 3

/// 4のindexを見つけます
int	find_4_index(t_node *node_a)
{
	int	i;

	i = 0;
	while (i < LEN4_MAX)
	{
		if (get_elem(node_a, i) == 1)
			return (i);
		i += 1;
	}
	return (-1);
}

/// 
/// 4抜きの長さ3の配列をセットする
void	set_arr_without_4(t_node *origin_node_a, int target_node_a[LEN3_MAX])
{
	int	i;

	i = 0;
	while (i < LEN3_MAX)
	{
		target_node_a[i] = get_elem(origin_node_a, i);
		i += 1;
	}
}

/// **紛らわしいから注意**
/// 引数は**リスト**!
int	len4_sort(t_node **node_a, t_node **node_b, t_node **ops)
{
	int		(*func[4])(t_node **node_a, t_node **ops);

	(void)node_b;
	if (is_sorted(*node_a))
		return (0);
	set_func_00(func);
	if (func[find_4_index(*node_a)](node_a, ops))
		return (1);
	if (len3_sort_base(node_a, ops, 2))
		return (1);
	if (push(ops, PA))
		return (1);
	if (optimize_ops(ops))
		return (1);
	return (0);
}
