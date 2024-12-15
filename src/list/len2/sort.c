
#include "../list.h"

int len2_sort(t_node **node_a, t_node**node_b,t_node **ops)
{
	int p;
	int q;
	(void) node_b;

	p = get_elem(*node_a, 0);
	q = get_elem(*node_a, 1);
	if (p > q)
		push(ops, SA);
	return (0);
}
