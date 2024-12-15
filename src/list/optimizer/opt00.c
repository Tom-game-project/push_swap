#include "../list.h"

/**
 * 最適化ルール
 * pa pb -> nop
 * pb pa -> nop
 * rra rrb -> rrr
 * rrb rra -> rrr
 */

/// for optimize
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

void optimize_ops(t_node **ops)
{
	int	n;

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

