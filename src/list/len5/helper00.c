
#include "../list.h"

int case_func_xxxoo(t_node **node_a, t_node **node_b, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}


int case_func_xxoxo(t_node **node_a,t_node **node_b,t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int case_func_xoxxo(t_node **node_a,t_node **node_b,t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 1, pop(node_a, 0)); // sa TODO 後でチェック
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, RRA);
	push(ops, PB);
	push(ops, SA);
	push(ops, PB);
	return (0);
}

int case_func_oxxxo(t_node **node_a,t_node **node_b,t_node **ops)
{
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}

int case_func_xxoox(t_node **node_a,t_node **node_b,t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	insert(node_a, 0, pop(node_a, len(*node_a) - 1)); // rra
	insert(node_b, 0, pop(node_a, 0)); // pb
	push(ops, RRA);
	push(ops, RRA);
	push(ops, PB);
	push(ops, RRA);
	push(ops, PB);
	return (0);
}
