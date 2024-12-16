#include "../list.h"
#include "opt01.h"

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

int optimize_ops(t_node **ops)
{
	if (opt_nop(ops))
		return (1);
	if (opt_rrr(ops))
		return (1);
	if (opt_rr(ops))
		return (1);
	return (0);
}
