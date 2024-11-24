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
#include <stdbool.h>

// test 
#include <stdio.h>

#include "list.h"
#include "../../src/output/output.h"


/**
 * 最適化ルール
 * pa pb -> nop
 * pb pa -> nop
 * rra rrb -> rrr
 * rrb rra -> rrr
 */

// 1回
static void	push_head_to_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, 0));
	if (f_f == 'a')
		push(ops, PB);
	else
		push(ops, PA);
}

// 2回
static void	push_second_to_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0,pop(f, 1));
	if (f_f == 'a')
	{
		push(ops, SA);
		push(ops, PB);
	}
	else
	{
		push(ops, SB);
		push(ops, PA);
	}
}


// 2回
static void	push_end_to_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, len(*f) - 1));
	if (f_f == 'a')
	{
		push(ops, RRA);
		push(ops, PB);
	}
	else
	{
		push(ops, RRB);
		push(ops, PA);
	}
}


static void push_head_to_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, len(*t) - 1, pop(f, 0));
	if (f_f == 'a')
	{
		push(ops, PA);
		push(ops, RRB);
	}
	else
	{
		push(ops, PB);
		push(ops, RRA);
	}
}


// 3回
static void push_second_to_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, len(*t) - 1, pop(f,1));
	if (f_f == 'a')
	{
		push(ops, SA);
		push(ops, PB);
		push(ops, RRB);
		
	}
	else
	{
		push(ops, SB);
		push(ops, PA);
		push(ops, RRA);
	}
}

// 3回
static void push_end_to_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
	push(t,  pop(f, len(*f) - 1));
	if (f_f == 'a')
	{
		push(ops, RRA);
		push(ops, PB);
		push(ops, RB);
	}
	else
	{
		push(ops, RRB);
		push(ops, PA);
		push(ops, RA);
	}
}


static void	print_poped(int poped)
{
	if (poped == SA)
		put_str("sa\n");
	else if (poped == SB)
		put_str("sb\n");
	else if (poped == SS) 
		put_str("ss\n"); 
	else if (poped == PA) 
		put_str("pa\n");
	else if (poped == PB)
		put_str("pb\n");
	else if (poped == RA)
		put_str("ra\n");
	else if (poped == RB)
		put_str("rb\n");
	else if (poped == RR)
		put_str("rr\n");
	else if (poped == RRA)
		put_str("rra\n");
	else if (poped == RRB)
		put_str("rrb\n");
	else if (poped == RRR)
		put_str("rrr\n");
	else
		put_str("Error!\n");
}

/// optimize function

int	find_nop(t_node *ops)
{
	int	i;
	int	len_ops;

	i = 0;
	len_ops = len(ops);
	while (i < len_ops - 1)
	{
		if (get_elem(ops, i) == PA && get_elem(ops, i + 1) == PB)
			return (i);
		else if (get_elem(ops, i) == PB && get_elem(ops, i + 1) == PA)
			return (i);
		i++;
	}
	return (-1);
}

int	shortening_rrr(t_node *ops)
{
	int	i;
	int	len_ops;

	i = 0;
	len_ops = len(ops);
	while (i < len_ops - 1)
	{
		if (get_elem(ops, i) == RRA && get_elem(ops, i + 1) == RRB)
			return (i);
		else if (get_elem(ops, i) == RRB && get_elem(ops, i + 1) == RRA)
			return (i);
		i++;
	}
	return (-1);
}

int shortening_rr(t_node *ops)
{
	int i;
	int len_ops;

	i=0;
	len_ops = len(ops);
	while (i < len_ops - 1)
	{
		if (get_elem(ops, i) == RA && get_elem(ops, i + 1) == RB)
			return (i);
		else if (get_elem(ops, i) == RB && get_elem(ops, i + 1) == RA)
			return (i);
		i++;
	}
	return (-1);
}


void	output_all_ops(t_node **ops)
{
	int	poped;

	while (*ops != NULL)
	{
		poped = pop(ops, 0);
		print_poped(poped);
	}
}

/// ここで、最初の処理します
static int init_sort(t_node **f, t_node **t, char f_f, t_node** ops)
{
	if (get_elem(*f, 0) < get_elem(*f, len(*f) - 1))
		push_end_to_head(f, t, f_f, ops);
	else
		push_head_to_head(f, t, f_f, ops);
	return (-1);
}


static bool all_minus(int a[6])
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (0 < a[i])
			return (false);
		i++;
	}
	return (true);
}


/// もっとも効率の良い、関数のindexを返却します
/// 
static int get_opt_index(int a[6])
{
	int i;
	int ri;

	i = 0;
	ri = 0;
	while (i < 6)
	{
		// いまのindexが0より大きく、今の最小よりも小さい
		// または
		// 今の最小が0より小さく、いまのindexが0より大きい
		// ときは
		// 最小値のindexを更新する
		if ((0 <= a[i] && a[i] < a[ri]) || (a[ri] < 0 && 0 <= a[i]))
			ri = i;
		i++;
	}
	return (ri);
}


/// @brief 
/// @param f from
/// @param t to
static void	move_stack(t_node **f, t_node **t, char f_f, t_node** ops)
{
	int	i;
	int a[6];
	void (*func[6])(t_node **f, t_node **t, char f_f, t_node** ops);

	i = init_sort(f, t, f_f, ops);
	func[0] = push_head_to_head;
	func[1] = push_second_to_head;
	func[2] = push_end_to_head;
	func[3] = push_head_to_end;
	func[4] = push_second_to_end;
	func[5] = push_end_to_end;
	while (*f != NULL)
	{
		a[0] = -1;
		a[1] = -1;
		a[2] = -1;
		a[3] = -1;
		a[4] = -1;
		a[5] = -1;

		a[0] = (get_elem(*t, 0) - get_elem(*f, 0)) * i; // push_head_to_head
		if (1 < len(*f))
			a[1] = (get_elem(*t, 0) - get_elem(*f, 1)) * i; // push_second_to_head
		a[2] = (get_elem(*t, 0) - get_elem(*f, len(*f) - 1)) * i; // push_end_to_head
		a[3] = (get_elem(*t, len(*t) - 1) - get_elem(*f, 0)) * i; // push_head_to_end
		if (1 < len(*f))
			a[4] = (get_elem(*t, len(*t) - 1) - get_elem(*f, 1)) * i; // push_second_to_end
		a[5] = (get_elem(*t, len(*t) - 1) - get_elem(*f, len(*f) - 1)) * i; //push_end_to_end
		printf("a[0] = %d\na[1] = %d\na[2] = %d\na[3] = %d\na[4] = %d\na[5] = %d\n",
				a[0],
				a[1],
				a[2],
				a[3],
				a[4],
				a[5]
				);
		printf("min index [%d]\n",get_opt_index(a));
		printf("all minus %d\n", all_minus(a));
		print_list(f);
		print_list(t);

		if (all_minus(a))
			i *= -1;
		else
			func[get_opt_index(a)](f, t, f_f, ops);
	}
}


void	merge_sort(t_node **node_a,t_node **node_b, t_node **ops)
{
	int	n;

	while (!is_sorted(*node_a))
	{
		move_stack(node_a, node_b, 'a', ops);
		move_stack(node_b, node_a, 'b', ops);
	}
	n = find_nop(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n);
		n = find_nop(*ops);
	}
	n = shortening_rrr(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n); 
		insert(ops, n, RRR);
		n = shortening_rrr(*ops);
	}
	n = shortening_rr(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n); 
		insert(ops, n, RR);
		n = shortening_rr(*ops);
	}
}

