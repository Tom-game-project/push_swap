#include "list.h"
#include "../../src/output/output.h"

#include <stdlib.h>

void	print_poped(int poped)
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
