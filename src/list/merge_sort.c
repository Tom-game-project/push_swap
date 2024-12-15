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

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#include "../../src/output/output.h"
#include "optimizer/opt.h"


/**
 * 最適化ルール
 * pa pb -> nop
 * pb pa -> nop
 * rra rrb -> rrr
 * rrb rra -> rrr
 */

static void	push_end(t_node **f, t_node**t, char f_f, t_node **ops)
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

static void	push_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, 0));
	if (f_f == 'a')
		push(ops, PB);
	else
		push(ops, PA);
}

static void	push_second(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, 1));
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

void	output_all_ops(t_node **ops)
{
	int	poped;

	while (*ops != NULL)
	{
		poped = pop(ops, 0);
		print_poped(poped);
	}
}

static int init_sort(t_node **f, t_node **t, char f_f, t_node** ops)
{
        if (get_elem(*f, 0) < get_elem(*f, len(*f) - 1))
                push_end(f, t, f_f, ops);
        else
                push_head(f, t, f_f, ops);
        return (1);
}

int get_min_exclude_minus(int ex[6],int *umin)
{
	int i;

	i = 0;
	*umin = 0;
	while (i < 6) // magic number
	{
		if (0 < ex[i] && ex[i] < ex[*umin])
			*umin = i;
		else if (ex[*umin] < 0 && 0 < ex[i])
			*umin = i;
		i += 1;
	}
	if (ex[*umin] < 0)
		return (1);
	return (0);
}

void set_minus(int ex[6])
{
	int i;

	i = 0;
	while (i < 6)
	{
		ex[i] = -1;
		i+=1;
	}
}

static void set_func( void (*func[6])(t_node **f, t_node**t, char f_f, t_node **ops))
{
	func[0] = push_head;
	func[1] = push_end;
	func[2] = push_second;
}


/// @brief 
/// @param f from
/// @param t to
static void	move_stack(t_node **f, t_node **t, char f_f, t_node** ops)
{
	int	i;
	int ex[6];
	int umin;
	void (*func[6])(t_node **f, t_node**t, char f_f, t_node **ops);

	i = init_sort(f, t, f_f, ops);
	set_func(func);
	while (*f != NULL)
	{
		set_minus(ex);
		ex[0] = (get_elem(*t, 0) - get_elem(*f, 0)) * i;
		ex[1] = (get_elem(*t, 0) - get_elem(*f, len(*f) - 1)) * i;
		if (1 < len(*f))
		    ex[2] = (get_elem(*t, 0) - get_elem(*f, 1)) * i;
		if (get_min_exclude_minus(ex, &umin))
			i *= -1;
		else
			func[umin](f, t, f_f, ops);
	}
}

int	merge_sort(t_node **node_a,t_node **node_b, t_node **ops)
{

	while (!is_sorted(*node_a))
	{
		move_stack(node_a, node_b, 'a', ops);
		move_stack(node_b, node_a, 'b', ops);
	}
	optimize_ops(ops);
	return (0);
}
