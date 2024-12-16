/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:59:02 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:19:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_checker/input_checker.h"
#include "output/output.h"
#include "strnumtools/strnumtools.h"
// list
#include "list/list.h"
#include "list/len2/len2.h"
#include "list/len3/len3.h"
#include "list/len4/len4.h"
#include "list/len5/len5.h"

#include <stdlib.h>

/// ここで、1から始まる配列にします
int	*create_list(int argc, char *argv[])
{
	int	*stack;
	int	i;
	int	j;
	int	c;

	stack = (int *) malloc(sizeof(int) * (argc - 1));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		c = 0;
		while (++j < argc)
		{
			if (lt(argv[i], argv[j]))
				c++;
		}
		stack[i - 1] = argc - 1 - c;
	}
	return (stack);
}

/// @brief if something wrong return 1
int	set_stack_a(t_node **a,int argc, char *argv[])
{
	int	*stack;
	int	i;

	i = 0;
	stack = create_list(argc, argv);
	if (stack == NULL)
		return (print_allocation_error(), 1);
	while (++i < argc)
	{
		if (push(a, stack[i - 1]))
			return (print_allocation_error(), free(stack), 1);
	}
	free(stack);
	return (0);
}

/// 重複を検知します
/// 重複を検知すると1を返す
int	check_duplicate(t_node **node_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < len(*node_a))
	{
		j = 0;
		while (j < len(*node_a))
		{
			if (i != j && get_elem(*node_a, i) == get_elem(*node_a, j))
				return (1);
			j += 1;
		}
		i += 1;
	}
	return (0);
}

int	my_sort(\
int (*func[5])(t_node **node_a, t_node **node_b, t_node **ops), \
t_node **node_a, \
t_node **node_b, \
t_node **ops)
{
	int	a_len;

	a_len = len(*node_a);
	func[0] = len2_sort;
	func[1] = len3_sort;
	func[2] = len4_sort;
	func[3] = len5_sort;
	func[4] = merge_sort;
	if (a_len == 1)
		return (0);
	else if (2 <= a_len && a_len <= 5)
		return (func[a_len - 2](node_a, node_b, ops));
	else
		return (func[4](node_a, node_b, ops));
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	t_node	*ops;
	int		(*func[5])(t_node **node_a, t_node **node_b, t_node **ops);

	if (!is_valid_all(argc, argv))
		return (print_error());
	a = NULL;
	b = NULL;
	ops = NULL;
	if (set_stack_a(&a, argc, argv))
		return (print_error());
	if (check_duplicate(&a))
		return (print_error(), clear(&a), 1);
	if (my_sort(func, &a, &b, &ops))
		return (print_allocation_error(), clear(&a), clear(&a), clear(&b), 1);
	else
		return (output_all_ops(&ops), clear(&a), clear(&b), 0);
	return (0);
}
