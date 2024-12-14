
#include "../list.h"

int case_func_xoxox(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 1, pop(node_a, 0)); // sa
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, SA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (1);
}

int case_func_oxxox(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (1);
}

int case_func_xooxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	push(node_a, pop(node_a, 0)); // ra
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, RA);
	push(ops, PB);
	push(ops, PB);
	return (1);
}

int case_func_oxoxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(node_a, pop(node_a, 0)); // ra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, PB);
	push(ops, RA);
	push(ops, PB);
	return (1);
}


int case_func_ooxxx(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, PB);
	push(ops, PB);
	return (1);
}
